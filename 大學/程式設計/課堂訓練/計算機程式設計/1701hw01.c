#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define shapeText(TYPE)	int ( *perimeter )( struct TYPE*);\
						int ( *area )( struct TYPE* ) ;
typedef struct shape_s 
{ 
	shapeText( shape_s ) ;
	// 等同於
	// int ( *perimeter )( struct shape_s* ) ; 為一函式指標 
	// int ( *area )( struct shape_s* ) ;      為一函式指標 
} shape_t ;
typedef struct circle_s 
{
	shapeText( circle_s ) ;
	// 等同於
	// int ( *perimeter )( struct circle_s* ) ; 為一函式指標 
	// int ( *area )( struct circle_s* ) ;      為一函式指標 
	int radius ;
} circle_t ;
typedef struct rectangle_s 
{
	shapeText( rectangle_s ) ;
	// 等同於
	// int ( *perimeter )( struct rectangle_s* ) ; 為一函式指標 
	// int ( *area )( struct rectangle_s* ) ;      為一函式指標 
	int width , height ;
} rectangle_t ;
typedef struct square_s
{
	shapeText( square_s ) ;
	// 等同於
	// int ( *perimeter )( struct square_s* ) ; 為一函式指標 
	// int ( *area )( struct square_s* ) ;      為一函式指標 
	int side ;
} square_t ;
typedef struct triangle_s 
{
	shapeText( triangle_s ) ;
	// 等同於
	// int ( *perimeter )( struct triangle_s* ) ; 為一函式指標 
	// int ( *area )( struct triangle_s* ) ;      為一函式指標 
	int s1, s2, s3;
} triangle_t ;
int CirclePerimeter(circle_t *obj) 
{
	return obj -> radius * 2 * 4  ;
}
int CircleArea(circle_t *obj) 
{
	return obj->radius * obj->radius * 4 ;	
}
void circleNew(circle_t *obj) 
{
    obj->perimeter = CirclePerimeter;
    // 使 obj 中的 perimeter函式指標 指向 CirclePerimeter 函式  
    obj->area = CircleArea;
    // 使 obj 中的 area函式指標 指向 CircleArea 函式 
}
int rectanglePerimeter(rectangle_t *obj) 
{
	return 2 * ( obj -> height + obj -> width ) ;
}
int rectangleArea(rectangle_t *obj) 
{
	return obj -> height * obj -> width ;
}
void rectangleNew( rectangle_t *obj )
{
	obj -> perimeter = rectanglePerimeter ;
	obj -> area = rectangleArea ;
	//同 CircleNew的解釋 
}
int trianglePerimeter( triangle_t *obj ) 
{
	return obj -> s1 + obj -> s2 + obj -> s3 ;
}
int triangleArea( triangle_t *obj ) 
{
	double count = ( obj -> s1 + obj -> s2 + obj -> s3 ) / 2 ;
	return sqrt( count*( count - obj -> s1)* ( count - obj -> s2)*( count - obj -> s3) ) ;
}
void triangleNew( triangle_t *obj )
{
	obj -> perimeter = trianglePerimeter ;
	obj -> area = triangleArea ;
	//同 CircleNew的解釋 
}
int squarePerimeter( square_t *obj ) 
{
	return obj -> side * 4 ;
}
int squareArea( square_t *obj ) 
{
	return obj -> side * obj -> side ;
}
void squareNew( square_t *obj )
{
	obj -> perimeter = squarePerimeter ;
	obj -> area = squareArea ;
	//同 CircleNew的解釋 
}
int main()
{
    int n ;
    scanf ( "%d" , &n ) ;
    int count_perimeter = 0 , count_area = 0 ;
    while ( n-- )
    {
    	char graph[10] ;
    	scanf( "%s" , graph ) ;
		if ( strcmp( graph , "circle" ) == 0 )
		{
			circle_t circle ;
			circleNew( &circle ) ;
			//使用circleNew的函式 使剛宣告的circle變數中尚未定義的perimeter跟area函式指標指向CirclePerimeter跟CircleArea函式 
			scanf( "%d" , &circle.radius ) ;
			shape_t *sp = ( shape_t *)( &circle ) ;
			//使 circle 強轉成 shape_t的指標型態 存入 shape_t的指標sp中 
			//類似於 
			//int i = 5 ;
			//float i_f = (float)(i)
			//的用法
			//此時 sp->perimeter=CirclePerimeter;
			//sp->perimeter指向CirclePerimeter"函式" 
			count_perimeter += sp -> perimeter( sp ) ; /
			//使用時 需用呼叫的形式來使用 故為 sp -> perimeter(sp) 
			// sp -> perimeter(sp) 的意義上等同於是呼叫 CirclePerimeter(sp); 函式 
			count_area += sp -> area( sp ) ; 
			//同上 
			printf( "circle %d %d\n" , sp -> perimeter( sp ) , sp -> area( sp ) ) ;
		} 
		else if ( strcmp( graph , "rectangle" ) == 0 )
		{
			//同circle 
			rectangle_t rectangle ;
			rectangleNew( &rectangle ) ;
			scanf( "%d%d" , &rectangle.width , &rectangle.height ) ;
			shape_t *sp = ( shape_t *)( &rectangle ) ;
			count_perimeter += sp -> perimeter( sp ) ;
			count_area += sp -> area( sp ) ; 
			printf( "rectangle %d %d\n" , sp -> perimeter( sp ) , sp -> area( sp ) ) ;
		}
		else if ( strcmp( graph , "square" ) == 0 )
		{
			//同circle 
			square_t square ;
			squareNew( &square ) ;
			scanf( "%d" , &square.side ) ;
			shape_t *sp = ( shape_t *)( &square ) ;
			count_perimeter += sp -> perimeter( sp ) ;
			count_area += sp -> area( sp ) ; 
			printf( "square %d %d\n" , sp -> perimeter( sp ) , sp -> area( sp ) ) ;
		}
		else
		{
			//同circle 
			triangle_t triangle ;
			triangleNew( &triangle ) ;
			scanf( "%d%d%d" , &triangle.s1 , &triangle.s2 , &triangle.s3 ) ;
			shape_t *sp = ( shape_t *)( &triangle ) ;
			count_perimeter += sp -> perimeter( sp ) ;
			count_area += sp -> area( sp ) ; 
			printf( "triangle %d %d\n" , sp -> perimeter( sp ) , sp -> area( sp ) ) ;
		}
	}
	printf( "%d %d\n" , count_perimeter , count_area ) ;
}
