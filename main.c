/**
 *
 * This is an example of how to use the hash table.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include "hashtable/hashtable.h"

int
main(int argc, char **argv) {
    size_t ht_size = 512;   // hash table size

    // we create the hash table by giving its size and
    // optionally a function pointer to a hash function.
    hashtable_t *ht = ht_create(ht_size, NULL);

    // then we can insert in a simple way
    ht_set(ht, "ht_k1", "jenna");
    ht_set(ht, "ht_k2", "jameson");
    printf(" ** key: %s has a value of %s\n",
           "ht_k2", ht_get(ht, "ht_k2"));
    // now, ht_k2 will be replaced.
    ht_set(ht, "ht_k2", "son goku");
    printf(" ** key: %s has a value of %s\n",
           "ht_k2", ht_get(ht, "ht_k2"));

    // removing an element returns its value if
    // it was found -- it's up to you to free it.
    char *skey = "ht_k2",
          *res = ht_rem(ht, skey);
    printf(" !! Removed key: %s, got value: %s\n", skey, res);
    // as we said previously, we have to free the
    // retrieved value ourselves.
    if(res) {free(res);}

    // finally we destroy the hash table itself.
    ht_destroy(ht);
    // OK.
    return 0;
}