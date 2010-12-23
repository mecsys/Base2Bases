/*
 * dltest.c - Dynamically load liberr.so and call err_ret
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
    void *handle;
    void (*errfcn)();		/* pointer to the loaded code to use */
    const char *errmsg;
    FILE *pf;
    
    /* Load the object of our desire */
    handle = dlopen("liberr.so", RTLD_NOW);
    if(handle == NULL) {
        fprintf(stderr, "failed to load liberr.so: %s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    
    /* Clear the error string, if any */
    dlerror();
    errfcn = dlsym(handle, "err_ret");
    if((errmsg = dlerror()) != NULL) {
        fprintf(stderr, "didn't find err_ret(): %s\n", errmsg);
        exit(EXIT_FAILURE);
    }
    /* Now use the loaded symbol, err_ret */
    if((pf = fopen(" foobar", "r")) == NULL) {
        errfcn("couldn't open foobar");
        fprintf(stdout, "liberr.so loaded!\n");
    }
    
    /* Be a good citizen and unload the object */
    dlclose(handle);
    exit(EXIT_SUCCESS);
}
