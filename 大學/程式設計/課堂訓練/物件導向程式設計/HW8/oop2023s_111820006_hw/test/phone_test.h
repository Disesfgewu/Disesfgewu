#include "../src/device.h"
#include "../src/phone.h"
TEST( PhoneCase, Create )
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
    ASSERT_EQ( phone1.name_of_type() , "phone");
}
TEST( PhoneCase, CreateDefaultThrowException )
{
    try
    {
        Phone phone10{15, "iOS"};
        FAIL();
    }
    catch(const std::string & e)
    {
        ASSERT_EQ( e , "Invalid Operation: Lack of phone number");
    }
}
TEST( PhoneCase, CreateWithNumberOnly  )
{
    Phone phone1{"0987654321"};
    ASSERT_EQ( phone1.number() , "0987654321");
}