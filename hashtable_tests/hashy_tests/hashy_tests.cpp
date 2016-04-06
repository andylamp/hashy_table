#include <sstream>
#include "gtest/gtest.h"
#include "../../hashtable/hashtable.h"

/**
 * Test that half fills a moderately sized hash table with
 * entries, then drains it. Hash function used here is the
 * Jenkins hash (which is the default).
 */
TEST(hashy_tests, test_jenkins_hash) {
    size_t ht_size = 1024;
    std::string skey = "key_",
                svalue = "value_";

    std::stringstream sskey, ssvalue;
    skey.append("key_");
    svalue.append("value_");

    hashtable_t *ht = ht_create(ht_size, NULL);


    for(int i = 0; i < ht_size/2; i++) {
        sskey << skey << i;
        ssvalue << svalue << i;

        ht_set(ht, (char *) sskey.str().c_str(),
               (char *) ssvalue.str().c_str());
        sskey.str(std::string());
        ssvalue.str(std::string());
    }

    for(int i = 0; i < ht_size/2; i++) {
        sskey << skey << i;
        ssvalue << svalue << i;

        char * val = ht_rem(ht, (char *) sskey.str().c_str());
        if(val) {free(val);}
        sskey.str(std::string());
    }
    EXPECT_EQ(ht->stored_elements, 0);
    EXPECT_EQ(ht_destroy(ht), 0);
}


/**
 * Test that half fills a moderately sized hash table with
 * entries, then drains it. Hash function used here is a
 * naive hash function, which was taken from the implementation
 * that this hash table forked on.
 *
 * This function is faster than the one given by Jenkins
 * but not even remotely as good.
 */
TEST(hashy_tests, test_naive_hash) {
    size_t ht_size = 1024;
    std::string skey = "key_",
            svalue = "value_";

    std::stringstream sskey, ssvalue;
    skey.append("key_");
    svalue.append("value_");

    hashtable_t *ht = ht_create(ht_size, &ht_hash);


    for(int i = 0; i < ht_size/2; i++) {
        sskey << skey << i;
        ssvalue << svalue << i;

        ht_set(ht, (char *) sskey.str().c_str(),
               (char *) ssvalue.str().c_str());
        sskey.str(std::string());
        ssvalue.str(std::string());
    }

    for(int i = 0; i < ht_size/2; i++) {
        sskey << skey << i;
        ssvalue << svalue << i;

        char * val = ht_rem(ht, (char *) sskey.str().c_str());
        if(val) {free(val);}
        sskey.str(std::string());
    }
    EXPECT_EQ(ht->stored_elements, 0);
    EXPECT_EQ(ht_destroy(ht), 0);
}

/**
 * Main test  stub.
 */
int
main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
