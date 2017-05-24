#include "gloabl.h"



int random(int start, int end)
{
    return start + (end - start)*rand() / RAND_MAX;
}
