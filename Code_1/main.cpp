#include <UnitTest++/UnitTest++.h>
#include "/media/Œ·˘Â‰ÓÒÚÛÔÌ˚Â/ƒÎˇ “»Ãœ¿ 3/Task_1/modAlphaCipher.h"
#include "/media/Œ·˘Â‰ÓÒÚÛÔÌ˚Â/ƒÎˇ “»Ãœ¿ 3/Task_1/modAlphaCipher.cpp"


SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("¿¡¬¿¡", modAlphaCipher("¿¡¬").encrypt("¿¿¿¿¿"));
    }
    TEST(LongKey) {
        CHECK_EQUAL("¿¡¬√ƒ",modAlphaCipher("¿¡¬√ƒ≈®∆").encrypt("¿¿¿¿¿"));
    }
    TEST(LowCaseKey) {
        CHECK_EQUAL("¿¡¬¿¡", modAlphaCipher("‡·‚").encrypt("¿¿¿¿¿"));
    }
    TEST(DigitsInKey) {
        CHECK_THROW(modAlphaCipher cp("¡1"), cipher_error);
    }
    TEST(PunctuationInKey) {
        CHECK_THROW(modAlphaCipher cp("¿,¡"), cipher_error);
    }
    TEST(WhitespaceInKey) {
        CHECK_THROW(modAlphaCipher cp("¿ ¡"), cipher_error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher cp(""), cipher_error);
    }
    TEST(WeakKey) {
        CHECK_THROW(modAlphaCipher cp("¿¿¿"), cipher_error);
    }
}
struct KeyB_fixture {
    modAlphaCipher* p;
    KeyB_fixture()
    {
        p = new modAlphaCipher("¡");
    }
    ~KeyB_fixture()
    {
        delete p;
    }
};
SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("Õ¡Õ¡Õ‹Ã¡—¡Õ‘", p->encrypt("Ã¿Ã¿Ã€À¿–¿Ã”"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("Õ¡Õ¡Õ‹Ã¡—¡Õ‘", p->encrypt("Ï‡Ï‡Ï˚Î‡‡ÏÛ"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("Õ¡Õ¡Õ‹Ã¡—¡Õ‘", p->encrypt("Ã‡Ï‡ Ï˚Î‡ ‡ÏÛ"));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt(""), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt("123123123"), cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("ÀﬂÀﬂÀ⁄ ﬂœﬂÀ“",modAlphaCipher("ﬂ").encrypt("Ã¿Ã¿Ã€À¿–¿Ã”"));
    }
}
SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("Ã¿Ã¿Ã€À¿–¿Ã”", p->decrypt("Õ¡Õ¡Õ‹Ã¡—¡Õ‘"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p -> decrypt("Ì¡Õ¡Õ‹Ã¡—¡Õ‘"), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
        CHECK_THROW(p->decrypt("Õ¡Õ¡ Õ‹Ã¡ —¡Õ‘"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, DigitsString) {
        CHECK_THROW(p -> decrypt("123123123"), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, PunctString) {
        CHECK_THROW(p -> decrypt("Õ¡Õ¡,Õ‹Ã¡—¡Õ‘"), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(""), cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("Ã¿Ã¿Ã€À¿–¿Ã”",modAlphaCipher("ﬂ").decrypt("ÀﬂÀﬂÀ⁄ ﬂœﬂÀ“"));
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}