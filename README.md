# Hashy table.

This is a simple, concise and (reasonably) fast implementation
of a hashtable in pure C.

# Usage

Using it is really simple; you just have to include the header
file in your project and you're good to go -- no external
dependencies are required.

This hash table comes with two hash functions to choose from, which
are the following:

 * **one-at-a-time** hash by Bob Jenkins
 (more info [here](http://www.burtleburtle.net/bob/hash/doobs.html))
 * **naive-hash** which is the same used in the initial hashtable
 [gist](https://gist.github.com/tonious/1377667)
 that this is based on.

 There are quite a bit of error and sanity checks... so it would be
 really resilient to misuse.

 # Examples

 A simple example is provided inside, but here are the basics:

 ## Creating

 Creating a hashtable:
 ```c
 size_t ht_size = 512;   // hash table size

 // we create the hash table by giving its size and
 // optionally a function pointer to a hash function.
 hashtable_t *ht = ht_create(ht_size, NULL);
 ```

 This will create a pointer to the hashtable data structure; then we
 can use it to perform all the operations that we support. These are:

 * insertions (`ht_set`)
 * fetches (`ht_get`)
 * deletions (`ht_rem`)

 # Inserting

 Insertions are again dead simple; after successful creation
 we can do the following:

 ```c
 ht_set(ht, "ht_k1", "jenna");
 ```

 where `kt_k1` is the `Key` and `jenna` is the `Value` --
 so we have a `(Key, Value)` pair. It has to be noted that we
 don't have duplicate keys -- so in the case of using the same key
  to in the function `ht_set` the value of that pair
  is **replaced** instead of having more than one
  `(Key, Value)` pairs. So should we do the following:


 ```c
 ht_set(ht, "ht_k1", "jenna");
 ht_set(ht, "ht_k1", "bobby");
 ```

 The value that the pair which has a key: `ht_k1` would be `bobby` and
 not `jenna`.

 # Fetching

 Fetching can be accomplished by probing our hashtable using a
 valid key, this can be accomplished like this:

 ```c
 char *res = ht_get(ht, "kt_k1");
 ```

 If the fetch is successful then a pointer `Value` of
 that `(Key, Value)` pair stored to `res`.

 # Deleting

 Deletion follows a similar fashion, so a deletion would look like this:

 ```c
 char *val = ht_rem(ht, "kt_k1");
 ```

 This would return a `Value` pointer of the `(Key, Value)` pair identified
 by the given `Key`. It has to be noted that the actual `Value` is not
 free'ed by this function. You have to do it manually -- that means that
 the above segment would produce a memory leak. The correct way to go about
 it would be as follows:

 ```c
 char *val = ht_rem(ht, "kt_k1");
        .
        .
 // do stuff with val...
        .
        .
 // now free it.
 if(val) {free(val);}
 ```

 # Final words

 This library is **not** thread safe, so please don't attempt to use it
 in multithreaded applications.



