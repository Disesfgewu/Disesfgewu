package mini_python;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

// the following exception is used whenever you have to implement something
class Todo extends Error {
  private static final long serialVersionUID = 1L;
  Todo() { super("TODO"); }
}

/* Values of Mini-Python.

   Two main differences wrt Python:

   - We use here machine integers (Java type `long`) while Python
     integers are arbitrary-precision integers (we could use Java
     big integers but we opt for simplicity here).

   - What Python calls a ``list'' is a resizeable array. In Mini-Python,
     there is no way to modify the length, so a mere Java array can be used.
*/

abstract class Value implements Comparable<Value> {
  abstract boolean isFalse();

  boolean isTrue() {
    return !isFalse();
    // throw new Todo(); // TODO (question 2)
  }

  long asInt() {
    if (!(this instanceof Vint))
      throw new Error("integer expected");
    return ((Vint) this).n;
  }

  Vlist asList() {
    if (!(this instanceof Vlist))
      throw new Error("list expected");
    return (Vlist) this;
  }
}

class Vnone extends Value {
  @Override
  boolean isFalse() {
    return true;
    // throw new Todo(); // TODO (question 2)
  }

  @Override
  public String toString() {
    return "None";
  }

  @Override
  public int compareTo(Value o) {
    return o instanceof Vnone ? 0 : -1;
  }
}

class Vbool extends Value {
  final boolean b;

  Vbool(boolean b) {
    this.b = b;
  }

  @Override
  public String toString() {
    return this.b ? "True" : "False";
  }

  @Override
  boolean isFalse() {
    return this.b == false;
    // throw new Todo(); // TODO (question 2)
  }

  @Override
  public int compareTo(Value o) {
    if (o instanceof Vnone)
      return 1;
    if (o instanceof Vbool) {
      boolean ob = ((Vbool) o).b;
      return b ? (ob ? 0 : 1) : (ob ? -1 : 0);
    }
    return -1;
  }
}

class Vint extends Value {
  final long n;

  Vint(long n) {
    this.n = n;
  }

  @Override
  public String toString() {
    return "" + this.n;
  }

  @Override
  boolean isFalse() {
    if ( this.n == 0 )
      return true;
    return false;
    // throw new Todo(); // TODO (question 2)
  }

  @Override
  public int compareTo(Value o) {
    if (o instanceof Vnone || o instanceof Vbool)
      return 1;
    if (o instanceof Vint) {
      long d = this.n - o.asInt();
      return d < 0 ? -1 : d > 0 ? 1 : 0;
    }
    return -1;
  }
}

class Vstring extends Value {
  final String s;

  Vstring(String s) {
    this.s = s;
  }

  @Override
  public String toString() {
    return this.s;
  }

  @Override
  boolean isFalse() {
    return this.s.isEmpty();
    // throw new Todo(); // TODO (question 2)
  }

  @Override
  public int compareTo(Value o) {
    if (o instanceof Vnone || o instanceof Vbool || o instanceof Vint)
      return 1;
    if (o instanceof Vstring)
      return this.s.compareTo(((Vstring) o).s);
    return -1;
  }
}

class Vlist extends Value {
  final Value[] l;

  Vlist(int n) {
    this.l = new Value[n];
  }

  Vlist(Value[] l1, Value[] l2) {
    this.l = new Value[l1.length + l2.length];
    System.arraycopy(l1, 0, l, 0, l1.length);
    System.arraycopy(l2, 0, l, l1.length, l2.length);
  }

  @Override
  public String toString() {
    StringBuffer b = new StringBuffer();
    b.append("[");
    for (int i = 0; i < this.l.length; i++) {
      if (i != 0)
        b.append(", ");
      b.append(this.l[i]);
    }
    b.append("]");
    return b.toString();
  }

  @Override
  boolean isFalse() {
    return this.l.length == 0;
    // throw new Todo(); // TODO (question 2)
  }

  @Override
  public int compareTo(Value o) {
    if (!(o instanceof Vlist))
      return -1;
    Value[] ol = ((Vlist) o).l;
    int n1 = this.l.length, n2 = ol.length;
    int i1 = 0, i2 = 0;
    for (; i1 < n1 && i2 < n2; i1++, i2++) {
      Value v1 = this.l[i1];
      Value v2 = ol[i2];
      int c = v1.compareTo(v2);
      if (c != 0)
        return c;
    }
    if (i1 < n1)
      return 1;
    if (i2 < n2)
      return -1;
    return 0;
  }
}

/* The following exception is used to interpret Python's `return`.

   Note: this is an unchecked exception, so that we don't have to
   add `throws` declarations to the visitor methods. */
class Return extends RuntimeException {
  private static final long serialVersionUID = 1L;

  final Value v;

  Return(Value v) {
    this.v = v;
  }
}

/* The interpreter starts here */

class Interp implements Visitor {

  /* The visitor methods do not return values (they have a `void` type).

     So, to return values when evaluating a constant or an expression,
     we use the following wrappers `evalConstant` and `evalExpr`.
     They call `accept` and the visitor assigns the variable `value`. */
  Value value = null;

  Value evalConstant(Constant c) {
    assert value == null; // check for non-reentrance
    c.accept(this);
    Value v = value;
    value = null;
    return v;
  }
  Value evalExpr(Expr e) {
    assert value == null; // check for non-reentrance
    e.accept(this);
    Value v = value;
    value = null;
    return v;
  }

  // interpreting constants is immediate
  public void visit(Cnone c) {
    this.value = new Vnone();
  }
  public void visit(Cbool c) {
    this.value = new Vbool(c.b);
  }
  public void visit(Cstring c) {
    this.value = new Vstring(c.s);
  }
  public void visit(Cint c) {
    this.value = new Vint(c.n);
  }

  // local variables
  HashMap<String, Value> vars;

  Interp() {
    this.vars = new HashMap<String, Value>();
  }

  // functions definitions (functions are global, hence `static`)
  static HashMap<String, Def> functions = new HashMap<String, Def>();

  // binary operators
  static Value binop(Binop op, Value v1, Value v2) {
    switch (op) {
    case Bsub:
      if ( v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n;
        long n2 = ( ( Vint ) v2 ).n;
        return new Vint( n1 - n2 );
      }
      break;  
    case Bmul:
      if ( v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vint( n1 * n2 );
      }
    case Bdiv:
      if ( v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        if ( n2 == 0 )
          return new Vbool( false );
        return new Vint( n1 / n2 );
      }
    case Bmod:
      if ( v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vint( n1 % n2 );
      }
      // throw new Todo(); // TODO (question 1)
    case Badd:
      if (v1 instanceof Vint && v2 instanceof Vint){
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vint( n1 + n2 );
      }
        // throw new Todo(); // TODO (question 1)
      if (v1 instanceof Vstring && v2 instanceof Vstring){
        String s1 = ( ( Vstring ) v1 ).s;
        String s2 = ( ( Vstring ) v2 ).s;
        return new Vstring( s1 + s2 );
        // throw new Todo(); // TODO (question 3)
      }
      if (v1 instanceof Vlist && v2 instanceof Vlist){
        Value[] list1 = ( (Vlist) v1 ).l;
        Value[] list2 = ( (Vlist) v2 ).l;
        return new Vlist(list1, list2);
        //throw new Todo(); // TODO (question 5)
      }
      break;
    case Beq:
      if (v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vbool(n1 == n2);
      }
      else if ( v1 instanceof Vbool && v2 instanceof Vbool ){
        boolean b1 = ( (Vbool) v1 ).b;
        boolean b2 = ( (Vbool) v2 ).b;
        return new Vbool(b1 == b2);
      }
      else if ( v1 instanceof Vlist && v2 instanceof Vlist ){
        long len1 = ( ( Vlist ) v1 ).l.length;
        long len2 = ( ( Vlist ) v2 ).l.length;
        if ( len1 != len2 )
          return new Vbool( false );
        for ( int i = 0 ; i < len1 ; ++i ){
          Value elem1 = ((Vlist) v1).l[i];
          Value elem2 = ((Vlist) v2).l[i];
          if (elem1 instanceof Vlist && elem2 instanceof Vlist) {
            Value result = binop(Binop.Beq, elem1, elem2); 
              if (((Vbool) result).b == false) {
                  return new Vbool(false);
              }
          }
          else if (elem1 instanceof Vint && elem2 instanceof Vint) {
            long n1 = ((Vint) elem1).n;
            long n2 = ((Vint) elem2).n;
            if (n1 != n2) {
                return new Vbool(false);
            }
          }
          else if ( elem1 instanceof Vstring && elem2 instanceof Vstring ){
            String s1 = ( ( Vstring ) elem1 ).s ;
            String s2 = ( ( Vstring ) elem2 ).s ;
            if ( s1.equals(s2) ){
              return new Vbool(true);
            }
          }
          else 
            return new Vbool(false);
        }
        return new Vbool( true);
      }
      else if ( v1 instanceof Vstring && v2 instanceof Vstring ){
        String s1 = ( ( Vstring ) v1 ).s ;
        String s2 = ( ( Vstring ) v2 ).s ;
        if ( s1.length() != s2.length() ){
          return new Vbool(false);
        }
        for ( int j = 0 ; j < s1.length() ; ++j ){
          if ( s1.charAt(j) != s2.charAt(j)) {
            return new Vbool(false);
          }
        }
        return new Vbool(true);
      }
      return new Vbool( true );

      // throw new Todo(); // TODO (question 2)
    case Bneq:
      if (v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
      }
      else if ( v1 instanceof Vbool && v2 instanceof Vbool ){
        boolean b1 = ( (Vbool) v1 ).b;
        boolean b2 = ( (Vbool) v2 ).b;
        return new Vbool( b1 != b2 );
      }
      else if ( v1 instanceof Vlist && v2 instanceof Vlist ){
        long len1 = ( ( Vlist ) v1 ).l.length;
        long len2 = ( ( Vlist ) v2 ).l.length;
        if ( len1 != len2 )
          return new Vbool( false );
        for ( int i = 0 ; i < len1 ; ++i ){
          Value elem1 = ((Vlist) v1).l[i];
          Value elem2 = ((Vlist) v2).l[i];
          if (elem1 instanceof Vlist && elem2 instanceof Vlist) {
            Value result = binop(Binop.Bneq, elem1, elem2); 
              if (((Vbool) result).b == true) {
                  return new Vbool(true);
              }
            }
            else if (elem1 instanceof Vint && elem2 instanceof Vint) {
                long n1 = ((Vint) elem1).n;
                long n2 = ((Vint) elem2).n;
                if (n1 != n2) {
                    return new Vbool( true);
                }
            }
            else if ( elem1 instanceof Vstring && elem2 instanceof Vstring ){
              String s1 = ( ( Vstring ) elem1 ).s ;
              String s2 = ( ( Vstring ) elem2 ).s ;
              if ( !s1.equals(s2) ){
                return new Vbool(true);
              }
            }
          }
          return new Vbool( false );
      }
      else if ( v1 instanceof Vstring && v2 instanceof Vstring ){
        String s1 = ( ( Vstring ) v1 ).s ;
        String s2 = ( ( Vstring ) v2 ).s ;
        if ( s1.length() != s2.length() ){
          return new Vbool(true);
        }
        for ( int j = 0 ; j < s1.length() ; ++j ){
          if ( s1.charAt(j) != s2.charAt(j)) {
            return new Vbool(true);
          }
        }
        return new Vbool(false);
      }
      return new Vbool( false );
      // throw new Todo(); // TODO (question 2)
    case Blt:
      if (v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vbool(n1 < n2);
      } else if ( v1 instanceof Vbool && v2 instanceof Vbool ){
        boolean b1 = ( (Vbool) v1 ).b;
        boolean b2 = ( (Vbool) v2 ).b;
        long n1, n2;
        if ( b1 == false )
          n1 = 0;
        else 
          n1 = 1;
        if ( b2 == false )
          n2 = 0;
        else
          n2 = 1;
        return new Vbool( n1 < n2 );
      }
      else if ( v1 instanceof Vlist && v2 instanceof Vlist ){
        long len1 = ( ( Vlist ) v1 ).l.length;
        long len2 = ( ( Vlist ) v2 ).l.length;
        long count = 0;
        if ( len1 > len2 )
          return new Vbool( false );
        else if ( len1 < len2 )
          return new Vbool( true );
        for ( int i = 0 ; i < len1 ; ++i ){
          Value elem1 = ((Vlist) v1).l[i];
          Value elem2 = ((Vlist) v2).l[i];
          if (elem1 instanceof Vlist && elem2 instanceof Vlist) {
            Value result = binop(Binop.Blt, elem1, elem2); 
              if (((Vbool) result).b == false) {
                  return new Vbool(false);
              }
            }
            else if (elem1 instanceof Vint && elem2 instanceof Vint) {
                long n1 = ((Vint) elem1).n;
                long n2 = ((Vint) elem2).n;
                if (n1 > n2) {
                    return new Vbool(false);
                }
                else if ( n1 == n2 )
                  count++;
            }
            else if ( elem1 instanceof Vstring && elem2 instanceof Vstring ){
              String s1 = ( ( Vstring ) elem1 ).s ;
              String s2 = ( ( Vstring ) elem2 ).s ;
              if ( s1.length() < s2.length() ){
                return new Vbool(true);
              }
              for ( int j = 0 ; j < s1.length() ; ++j ){
                if ( s1.charAt(j) > s2.charAt(j)){
                  return new Vbool(false);
                }
                else if ( s1.charAt(j) == s2.charAt(j)) {
                  ++count;
                }
              }
              if ( count == s1.length() )
                return new Vbool(false);
            }
          }
          if ( count == len1 )
            return new Vbool( false );
          return new Vbool( true );
        }
        else if ( v1 instanceof Vstring && v2 instanceof Vstring ){
          String s1 = ( ( Vstring ) v1 ).s ;
          String s2 = ( ( Vstring ) v2 ).s ;
          long count = 0;
          if ( s1.length() > s2.length() ){
            return new Vbool(false);
          }
          else if ( s1.length() < s2.length() ){
            return new Vbool(true);
          }
          for ( int j = 0 ; j < s1.length() ; ++j ){
            if ( s1.charAt(j) > s2.charAt(j)) {
              return new Vbool(false);
            }
            else if ( s1.charAt(j) == s2.charAt(j)) {
              ++count;
            }
          }
          if ( count == s1.length() )
            return new Vbool(false);
          else
            return new Vbool(true);
        }
        return new Vbool(false);
      // throw new Todo(); // TODO (question 2)
    case Ble:
      if (v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vbool(n1 <= n2);
      }
      else if ( v1 instanceof Vbool && v2 instanceof Vbool ){
        boolean b1 = ( (Vbool) v1 ).b;
        boolean b2 = ( (Vbool) v2 ).b;
        long n1, n2;
        if ( b1 == false )
          n1 = 0;
        else 
          n1 = 1;
        if ( b2 == false )
          n2 = 0;
        else
          n2 = 1;
        return new Vbool( n1 <= n2 );
      }
      else if ( v1 instanceof Vlist && v2 instanceof Vlist ){
        long len1 = ( ( Vlist ) v1 ).l.length;
        long len2 = ( ( Vlist ) v2 ).l.length;
        if ( len1 > len2 )
          return new Vbool( false );
        else if ( len1 < len2 )
          return new Vbool( true );
        for ( int i = 0 ; i < len1 ; ++i ){
          Value elem1 = ((Vlist) v1).l[i];
          Value elem2 = ((Vlist) v2).l[i];
          if (elem1 instanceof Vlist && elem2 instanceof Vlist) {
            Value result = binop(Binop.Blt, elem1, elem2); 
              if (((Vbool) result).b == false) {
                  return new Vbool(false);
              }
            }
            else if (elem1 instanceof Vint && elem2 instanceof Vint) {
                long n1 = ((Vint) elem1).n;
                long n2 = ((Vint) elem2).n;
                if (n1 > n2) {
                    return new Vbool(false);
                }
            }
          }
          return new Vbool( true );
        }
        else if ( v1 instanceof Vstring && v2 instanceof Vstring ){
          String s1 = ( ( Vstring ) v1 ).s ;
          String s2 = ( ( Vstring ) v2 ).s ;
          long count = 0;
          if ( s1.length() > s2.length() ){
            return new Vbool(false);
          }
          else if ( s1.length() < s2.length()) {
            return new Vbool(true);
          }
          for ( int j = 0 ; j < s1.length() ; ++j ){
            if ( s1.charAt(j) > s2.charAt(j)) {
              return new Vbool(false);
            }
          }
          return new Vbool(true);
        }
      return new Vbool(false);
      // throw new Todo(); // TODO (question 2)
    case Bgt:
      if (v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vbool(n1 > n2);
      }
      else if ( v1 instanceof Vbool && v2 instanceof Vbool ){
        boolean b1 = ( (Vbool) v1 ).b;
        boolean b2 = ( (Vbool) v2 ).b;
        long n1, n2;
        if ( b1 == false )
          n1 = 0;
        else 
          n1 = 1;
        if ( b2 == false )
          n2 = 0;
        else
          n2 = 1;
        return new Vbool( n1 > n2 );
      }
      else if ( v1 instanceof Vlist && v2 instanceof Vlist ){
        long len1 = ( ( Vlist ) v1 ).l.length;
        long len2 = ( ( Vlist ) v2 ).l.length;
        long count = 0;
        if ( len1 > len2 )
          return new Vbool( false );
        else if ( len1 < len2 )
          return new Vbool( true );
        for ( int i = 0 ; i < len1 ; ++i ){
          Value elem1 = ((Vlist) v1).l[i];
          Value elem2 = ((Vlist) v2).l[i];
          if (elem1 instanceof Vlist && elem2 instanceof Vlist) {
            Value result = binop(Binop.Blt, elem1, elem2); 
              if (((Vbool) result).b == false) {
                  return new Vbool(false);
              }
            }
            else if (elem1 instanceof Vint && elem2 instanceof Vint) {
                long n1 = ((Vint) elem1).n;
                long n2 = ((Vint) elem2).n;
                if (n1 < n2) {
                    return new Vbool(false);
                }
                else if ( n1 == n2 )
                  count++;
            }
          }
          if ( count == len1 )
            return new Vbool( false );
          return new Vbool( true );
        }
        else if ( v1 instanceof Vstring && v2 instanceof Vstring ){
          String s1 = ( ( Vstring ) v1 ).s ;
          String s2 = ( ( Vstring ) v2 ).s ;
          long count = 0;
          if ( s1.length() < s2.length() ){
            return new Vbool(false);
          }
          else if ( s1.length() > s2.length()) {
            return new Vbool(true);
          }
          for ( int j = 0 ; j < s1.length() ; ++j ){
            if ( s1.charAt(j) < s2.charAt(j)) {
              return new Vbool(false);
            }
            else if ( s1.charAt(j) == s2.charAt(j) )
              count++;
          }
          if ( count == s1.length() )
            return new Vbool(false);
          return new Vbool(true);
        }
      return new Vbool(false); // TODO (question 2)
    case Bge:
      if (v1 instanceof Vint && v2 instanceof Vint ) {
        long n1 = ( ( Vint ) v1 ).n ;
        long n2 = ( ( Vint ) v2 ).n ;
        return new Vbool(n1 >= n2);
      }
      else if ( v1 instanceof Vbool && v2 instanceof Vbool ){
        boolean b1 = ( (Vbool) v1 ).b;
        boolean b2 = ( (Vbool) v2 ).b;
        long n1, n2;
        if ( b1 == false )
          n1 = 0;
        else 
          n1 = 1;
        if ( b2 == false )
          n2 = 0;
        else
          n2 = 1;
        return new Vbool( n1 >= n2 );
      }
      else if ( v1 instanceof Vlist && v2 instanceof Vlist ){
        long len1 = ( ( Vlist ) v1 ).l.length;
        long len2 = ( ( Vlist ) v2 ).l.length;
        long count = 0;
        if ( len1 > len2 )
          return new Vbool( false );
        else if ( len1 < len2 )
          return new Vbool( true );
        for ( int i = 0 ; i < len1 ; ++i ){
          Value elem1 = ((Vlist) v1).l[i];
          Value elem2 = ((Vlist) v2).l[i];
          if (elem1 instanceof Vlist && elem2 instanceof Vlist) {
            Value result = binop(Binop.Blt, elem1, elem2); 
              if (((Vbool) result).b == false) {
                  return new Vbool(false);
              }
            }
            else if (elem1 instanceof Vint && elem2 instanceof Vint) {
                long n1 = ((Vint) elem1).n;
                long n2 = ((Vint) elem2).n;
                if (n1 < n2) {
                    return new Vbool(false);
                }
                else if ( n1 == n2 )
                  count++;
            }
          }
          if ( count == len1 )
            return new Vbool( false );
          return new Vbool( true );
        }
        else if ( v1 instanceof Vstring && v2 instanceof Vstring ){
          String s1 = ( ( Vstring ) v1 ).s ;
          String s2 = ( ( Vstring ) v2 ).s ;
          if ( s1.length() < s2.length() ){
            return new Vbool(false);
          }
          else if ( s1.length() > s2.length()) {
            return new Vbool(true);
          }
          for ( int j = 0 ; j < s1.length() ; ++j ){
            if ( s1.charAt(j) < s2.charAt(j)) {
              return new Vbool(false);
            }
          }
          return new Vbool(true);
        }
      return new Vbool(false); // TODO (question 2)
    default:
    }
    throw new Error("unsupported operand types");
  }

  // interpreting expressions

  @Override
  public void visit(Ecst e) {
    this.value = evalConstant(e.c);
  }

  @Override
  public void visit(Ebinop e) {
    Value v1 = evalExpr(e.e1);
    switch (e.op) {
    case Band:
      if (v1 instanceof Vbool) {
        boolean b1 = ((Vbool) v1).b; 
        if (!b1) {  
            this.value = new Vbool(false); 
            return;  
        }
        Value v2 = evalExpr(e.e2);  
        if (v2 instanceof Vbool) {
            boolean b2 = ((Vbool) v2).b; 
            this.value = new Vbool(b1 && b2); 
        }
      }
      break;
      // throw new Todo(); // TODO (question 2)
    case Bor:
      if (v1 instanceof Vbool) {
        boolean b1 = ((Vbool) v1).b;  
        if (b1) { 
            this.value = new Vbool(true); 
            return; 
        }
        Value v2 = evalExpr(e.e2);
        if (v2 instanceof Vbool) {
            boolean b2 = ((Vbool) v2).b; 
            this.value = new Vbool(b1 || b2); 
        }
      }
      break;
      // throw new Todo(); // TODO (question 2)
    default:
      this.value = binop(e.op, v1, evalExpr(e.e2));
    }
  }

  @Override
  public void visit(Eunop e) {
    switch (e.op) {
    case Unot:
    Value v1 = evalExpr(e.e);
      if (v1 instanceof Vbool) {
        boolean b = ((Vbool) v1).b; 
        this.value = new Vbool(!b); 
      }
      break;
      //throw new Todo(); // TODO (question 2)
    case Uneg:
      Value v2 = evalExpr(e.e);
      if ( v2 instanceof Vint ){
        this.value = new Vint( -( ( Vint ) v2 ).n ) ;
      }
      break;
      // throw new Todo(); // TODO (question 1)
    }
  }

  @Override
  public void visit(Eident id) {
    String varName = id.x.id; 
    Value v = this.vars.get(varName); 
    if (v == null) { 
        throw new Error("undefined variable " + varName);
    }
    this.value = v; 
    // throw new Todo(); // TODO (question 3)
  }

  @Override
  public void visit(Ecall e) {
    switch (e.f.id) {
    case "len":
        if (e.l.size() != 1) {
            throw new Error("len() takes exactly one argument");
        }
        Value argValue = evalExpr(e.l.get(0));

        if (argValue instanceof Vlist) {
            this.value = new Vint(((Vlist) argValue).l.length);
        }
        else {
            throw new Error("len() argument must be a list");
        }
        break;
    case "list":
        Value[] values = new Value[e.l.size()];
        for (int i = 0; i < e.l.size(); i++) {
          values[i] = evalExpr(e.l.get(i));
        }
        if (values.length == 1 && values[0] instanceof Vlist) {
          this.value = values[0];
      } else {
          this.value = new Vlist(values, new Value[0]);
      }
        // throw new Todo(); // TODO (question 5)
        break;
    case "range":
        if (e.l.size() != 1) {
            throw new Error("range() takes exactly one argument");
        }

        Value rangeArg = evalExpr(e.l.get(0));
        if (!(rangeArg instanceof Vint)) {
            throw new Error("range() argument must be an integer");
        }

        int n = (int) ((Vint) rangeArg).n;
        if (n < 0) {
            throw new Error("range() argument must be non-negative");
        }

        Value[] rangeValues = new Value[n];
        for (int i = 0; i < n; i++) {
            rangeValues[i] = new Vint(i);
        }

        this.value = new Vlist(rangeValues, new Value[0]);
        
        // throw new Todo(); // TODO (question 5)
        break;
        default:
          Def func = functions.get(e.f.id);
          if (func == null) {
              throw new Error("undefined function " + e.f.id);
          }

          HashMap<String, Value> oldVars = new HashMap<>(this.vars);

          if (e.l.size() != func.l.size()) {
              throw new Error("wrong number of arguments for function " + e.f.id);
          }

          List<Value> argValues = new ArrayList<>();

          for (int i = 0; i < e.l.size(); i++) {
              Value nowargValue = evalExpr(e.l.get(i));
              argValues.add(nowargValue);  
          }
          for (int i = 0; i < argValues.size(); i++) {
              String paramName = func.l.get(i).id;  
              this.vars.put(paramName, argValues.get(i)); 
          }

          try {
              func.s.accept(this);  
              this.value = new Vnone();
          } catch (Return r) {
              this.value = r.v;
          } finally {
              this.vars.clear();  
              this.vars.putAll(oldVars);  
          }
          break;
      // throw new Todo(); // TODO (question 4)
    }
  }

  @Override
  public void visit(Elist e) {
    Value[] elements = new Value[e.l.size()];
    for (int i = 0; i < e.l.size(); i++) {
        elements[i] = evalExpr(e.l.get(i)); 
    }
    this.value = new Vlist(elements, new Value[0]); 
    // throw new Todo(); // TODO (question 5)
  }

  @Override
  public void visit(Eget e) {
      Value listValue = evalExpr(e.e1);
      Value indexValue = evalExpr(e.e2);

      if (!(listValue instanceof Vlist)) {
          throw new IllegalArgumentException("Expected a list.");
      }
      if (!(indexValue instanceof Vint)) {
          throw new IllegalArgumentException("Index must be an integer.");
      }

      Vlist list = (Vlist) listValue;
      int index = (int) ((Vint) indexValue).n;
      if (index < 0) {
          index += list.l.length;
      }

      if (index < 0 || index >= list.l.length) {
          throw new IndexOutOfBoundsException("Index out of bounds.");
      }

      this.value = list.l[index];
  }

  // throw new Todo(); // TODO (question 5)

  
  // interpreting statements

  @Override
  public void visit(Seval s) {
    s.e.accept(this);
  }

  @Override
  public void visit(Sprint s) {
    System.out.println(evalExpr(s.e).toString());
  }

  @Override
  public void visit(Sblock s) {
    for (Stmt st: s.l)
      st.accept(this);
  }

  @Override
  public void visit(Sif s) {
    Value condition = evalExpr(s.e);
    if ( condition instanceof Vbool ) {
        if ( ( ( Vbool ) condition ).b ) {
            s.s1.accept( this ); 
        } else if (s.s2 != null) {
            s.s2.accept( this );
        }
    } else if ( condition instanceof Vint ) {
      if (( ( Vint ) condition ).n != 0) { 
          s.s1.accept( this );
      } else if (s.s2 != null) {
          s.s2.accept(this); 
      }
    } 
    else {
        throw new Error("Condition must be a boolean");
    }
    // throw new Todo(); // TODO (question 2)
  }

  @Override
  public void visit(Sassign s) {
    String varName = s.x.id;
    Value valueToAssign = evalExpr(s.e); 
    this.vars.put(varName, valueToAssign); 
    // throw new Todo(); // TODO (question 3)
  }

  @Override
  public void visit(Sreturn s) {
    Value returnValue = evalExpr(s.e);
    if (s.e == null) {
      throw new Error("return statement requires an expression");
    }  
    throw new Return(returnValue);
    // throw new Todo(); // TODO (question 4)
  }

  @Override
  public void visit(Sfor s) {
    Value listValue = evalExpr(s.e); 
    Vlist list = listValue.asList(); 
    for (Value item : list.l) {
        this.vars.put(s.x.id, item); 
        s.s.accept(this); 
    }
    // throw new Todo(); // TODO (question 5)
  }

  @Override
  public void visit(Sset s) {
    Vlist list = evalExpr(s.e1).asList();  
    int index = (int) evalExpr(s.e2).asInt();  

    if (index < 0 || index >= list.l.length) {
        throw new Error("Index out of bounds");
    }

    Value valueToAssign = evalExpr(s.e3);  
    list.l[index] = valueToAssign;  
    // throw new Todo(); // TODO (question 5)
  }
}
