#include "../src/find.h"
#include "../src/device.h"
#include <vector>
using namespace std;

TEST( FindCase, CompareSize )
{
    Phone phone1{10, "Android", "0987654321"};
    Phone phone2{10, "iOS", "0984235689"};
    Phone phone3{11, "iOS", "0917833546"};
    Phone phone4{11, "Android", "0913974228"};
    Phone phone5{12, "Android", "0962534567"};
    Phone phone6{12, "Android", "0963829641"};
    Phone phone7{13, "Android", "0961144471"};
    Phone phone8{15, "iOS", "0963693353"};
    Phone phone9{15, "Android", "0918552436"};
    Phone phone10{15, "iOS", "0937449429"};
    vector <Device* > v = { &phone1 , &phone3 , &phone8 , &phone5 } ;
    vector <Device* > _one = find_device( v.begin() , v.end() , [](Device *D){
        if ( D -> size() == 12 )
            return true;
        else
            return false;
    } );
    ASSERT_EQ( _one[0] -> size() , 12 );
}
TEST( FindCase, CompareOs )
{
    Phone phone1{10, "Android", "0987654321"};
    Phone phone2{10, "iOS", "0984235689"};
    Phone phone3{11, "iOS", "0917833546"};
    Phone phone4{11, "Android", "0913974228"};
    Phone phone5{12, "Android", "0962534567"};
    Phone phone6{12, "Android", "0963829641"};
    Phone phone7{13, "Android", "0961144471"};
    Phone phone8{15, "iOS", "0963693353"};
    Phone phone9{15, "Android", "0918552436"};
    Phone phone10{15, "iOS", "0937449429"};
    vector <Device* > v = { &phone1 , &phone3 , &phone8 , &phone5 } ;
    vector <Device* > _one = find_device( v.begin() , v.end() , [](Device *D){
        if ( D -> os() == "iOS" )
            return true;
        else
            return false;
    } );
    ASSERT_EQ( _one[0] -> os() , "iOS" );
}