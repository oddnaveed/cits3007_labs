#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void fill_buffer(
    const char *dir, size_t dirlen, const char *fname, size_t filelen,
    const char *ext, size_t extlen, char *path)
{
    // copy the dir name
    strncpy(path, dir, dirlen);
    // add slash "/"
    strncpy(path + dirlen, "/", 1);
    // copy the file name
    strncpy(path + dirlen + 1, fname, filelen);
    // add dot "."
    strncpy(path + dirlen + 1 + filelen, ".", 1);
    // copy the ext
    strncpy(path + dirlen + 1 + filelen + 1, ext, extlen + 1);

    // path[strlen(path)] = '\0'; //! index不用-1
    // char s = "hello";
    // printf("length of string s is %d\n", s);   // 5
    // s[5] = '\0';
}

/** Return true when the sum of dirlen, filelen, extlen and 3
 * would exceed the maximum possible value of a size_t; otherwise,
 * return false.
 */
bool would_wrap_around(size_t dirlen, size_t filelen, size_t extlen)
{
    // That means if we have two size_t values, and we add them together – if the result is less than either of the values, we’ve suffered wraparound, and should exit early
    size_t sum = 0;
    if ((dirlen + filelen) < dirlen || (dirlen + filelen) < filelen)
        return true;

    sum = dirlen + filelen;
    if ((sum + extlen) < sum || (sum + extlen) < extlen)
        return true;

    sum += extlen;

    if ((sum + 3) < sum || (sum + 3) < 3)
        return true;

    return false;
}

char *make_pathname(const char *dir, const char *fname, const char *ext)
{
    // 1.Calculate the lengths of the input parameters. Then work out the amount of memory needed to hold the final resulting string. (We need enough space to hold all of the original strings concatenated together, plus a forward-slash character, plus a full stop, plus a NUL terminating byte.)
    size_t dirlen = strlen(dir);
    size_t filelen = strlen(fname);
    size_t extlen = strlen(ext);

    if (would_wrap_around(dirlen, filelen, extlen))
    {
        printf("error: overflow occurs\n");
        return NULL;
    }

    size_t total_length = dirlen + 1 + filelen + 1 + extlen;
    long unsigned int total_memory = sizeof(char) * total_length;

    // 2.Use malloc to allocate the amount of memory required; if the call to malloc fails, we should return a NULL pointer.
    char *path = malloc(total_memory);

    // 3.Copy the parameters into our malloced buffer, at the correct locations, and write the forward slash and dot at their correct locations.
    // copy the dir name
    strncpy(path, dir, dirlen);
    // add slash "/"
    path[dirlen] = '/';
    // copy the file name
    strncpy(path + dirlen + 1, fname, filelen);
    // add dot "."
    path[dirlen + 1 + filelen] = '.';
    // copy the ext
    strncpy(path + dirlen + 1 + filelen + 1, ext, extlen + 1);

    return path;
}

int main()
{
    // printf("size of char is %d\n", sizeof(char));
    // char *path = malloc(3 + 3 + 1 + 1 + 1 + 1);
    // fill_buffer("dev", 3, "lab", 3, "c", 1, path);
    // printf("path is %s\n", path);
    char *path = make_pathname("dir1", "file1", "cpp");
    printf("path is %s\n", path);

    return 0;
}
