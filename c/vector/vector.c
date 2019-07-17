typedef struct vec
{
    unsigned char* _mem;
    unsigned long _elems;
    unsigned long _elemsize;
    unsigned long _capelems;
    unsigned long _reserve;
};

vec* vec_new(unsigned long elemsize)
{
    vec* pvec = (vec*)malloc(sizeof(vec));
    pvec->_reserve = 10;
    pvec->_capelems = pvec->_reserve;
    pvec->_elemsize = elemsize;
    pvec->_elems = 0;
    pvec->_mem = (unsigned char*)malloc(pvec->_capelems * pvec->_elemsize);
    return pvec;
}

void vec_delete(vec* pvec)
{
    free(pvec->_mem);
    free(pvec);
}

void vec_grow(vec* pvec)
{
    unsigned char* mem = (unsigned char*)malloc((pvec->_capelems + pvec->_reserve) * pvec->_elemsize);
}