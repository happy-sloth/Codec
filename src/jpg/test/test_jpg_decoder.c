#include "unity.h"
#include "jpg_codec.h"


void test_jpg_decode_Should_return_CODEC_ERR (void)
{
    TEST_ASSERT_EQUAL(CODEC_ERR, jpg_decode());
    FILE *file = fopen("123.txt", "rb");
    TEST_ASSERT(file != NULL)
    TEST_ASSERT_EQUAL(CODEC_OK, trust_jpg_file(file));
    TEST_ASSERT_EQUAL(CODEC_ERR, jpg_decode());
    fclose(file);
}

void test_jpg_decode_Should_return_CODEC_OK (void)
{
    FILE* file = fopen("12ab.jpg", "rb");
    TEST_ASSERT(file != NULL)
    TEST_ASSERT_EQUAL(CODEC_OK, trust_jpg_file(file));
    TEST_ASSERT_EQUAL(CODEC_OK, jpg_decode());
    fclose(file);
}

void test_jpg_decode_send_broken_file_should_return_err(void)
{
    FILE* file = fopen("12abBroken.jpg", "rb");
    TEST_ASSERT(file != NULL)
    TEST_ASSERT_EQUAL(CODEC_OK, trust_jpg_file(file));
    TEST_ASSERT_EQUAL(CODEC_ERR, jpg_decode());
    fclose(file);
}

int main (void)
{
    UNITY_BEGIN();

    RUN_TEST(test_jpg_decode_Should_return_CODEC_ERR);
    RUN_TEST(test_jpg_decode_Should_return_CODEC_OK);
    RUN_TEST(test_jpg_decode_send_broken_file_should_return_err);
    return UNITY_END();
}
