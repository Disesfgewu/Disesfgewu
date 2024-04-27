#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define shapeText(TYPE)	int ( *perimeter )( struct TYPE*);\
						int ( *area )( struct TYPE* ) ;
typedef struct shape_s 
{ 
	shapeText( shape_s ) ;
} shape_t ;
typedef struct circle_s 
{
	shapeText( circle_s ) ;
	int radius ;
} circle_t ;
typedef struct rectangle_s 
{
	shapeText( rectangle_s ) ;
	int width , height ;
} rectangle_t ;
typedef struct square_s
{
	shapeText( square_s ) ;
	int side ;
} square_t ;
typedef struct triangle_s 
{
	shapeText( triangle_s ) ;
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
    obj->area = CircleArea;
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
}
int trianglePerimeter( triangle_t *obj ) 
{
	return obj -> s1 + obj -> s2 + obj -> s3 ;
}
int triangleArea( triangle_t *obj ) 
{
	double count = ( obj -> s1 + obj -> s2 + obj -> s3 ) / 2 ;
	return sqrt( count*( count - obj -> s1)*( count - obj -> s2)*( count - obj -> s3) ) ;
}
void triangleNew( triangle_t *obj )
{
	obj -> perimeter = trianglePerimeter ;
	obj -> area = triangleArea ;
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
			scanf( "%d" , &circle.radius ) ;
			shape_t *sp = ( shape_t *)( &circle ) ;
			count_perimeter += sp -> perimeter( sp ) ;
			count_area += sp -> area( sp ) ; 
			printf( "circle %d %d\n" , sp -> perimeter( sp ) , sp -> area( sp ) ) ;
		} 
		else if ( strcmp( graph , "rectangle" ) == 0 )
		{
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
