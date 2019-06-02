#include <unittest++/UnitTest++.h>
#include "Skital.h"

SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("deySSiaysIas",Swap(4).encrypt("IaSdaySessiy"));
    }
    
    TEST(LongKey) {
        CHECK_EQUAL("#yisseSyadSaI",Swap(13).encrypt("IaSdaySessiy"));
    }
    TEST(OneInKey) {
        CHECK_THROW(Swap cp(1),cipher_error);
    }
    TEST(ZeroInKey) {
        CHECK_THROW(Swap cp(0),cipher_error);
    }
}

struct KeyB_fixture {
    Swap * p;
    KeyB_fixture() {
        p = new Swap(3);
    }
    ~KeyB_fixture() {
        delete p;
    }
};

SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture,Strokawithsymbols) {
        CHECK_EQUAL("SysyaaeiI&Ss",p->encrypt("IaS&aySessiy"));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt(""),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, StringWithSpace) {
        CHECK_THROW(p->encrypt("Ia Sday Sessiy"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, Invalidsymvol) {
        CHECK_THROW(p->encrypt("IaSday##Sessiy"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, OneSymbol) {
        CHECK_THROW(p->encrypt("I"),cipher_error);
    }
}

SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture,Decryptwithsymbols) {
        CHECK_EQUAL("IaS&aySessiy",p->decrypt("SysyaaeiI&Ss"));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(""),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, OneSymbol) {
        CHECK_THROW(p->decrypt("I"),cipher_error);
    }
}


int main()
{
    return UnitTest::RunAllTests();
}
