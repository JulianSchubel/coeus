/* **************************************
    Title:          Permutations and Combinations
    Description:    Familiar counting methods from discrete mathematics
                                                                            With Reptitions        Without Repitions
                    (Permutations / Sequence) Order Matters:                n^r                    nPr
                    (Combinations / Subsets)  Order does not Matter:        n+(r-1)Cr              nCr                        
    
                    n: objects in the set
                    r: number of times a selection from the set is made

    Author:         Julian Schubel
    Contact:

    History:
    ///:            17/06/2022
************************************** */

/* For each selection there are n possibile choices. In otherwords the multilication rule for counting in simple form 
    e.g. set of 2 with 3 choices:
          +           +
        /   \       /   \
       +     +     +     +
      / \   / \   / \   / \
     +   + +   + +   + +   +

    i.e. 2^3, or generally n^r
*/

unsigned long int nr(int n, int r)
{
    if(r == 0)
    {
        return 0;
    }
    unsigned long int output = 1;    
    int i = 0;

    /* n^r */
    while(i < r)
    {
        output *= n; 
        ++i;
    }

    return output;
}

/*
    For each selection after the first we have n-1 options;
    Thus for r selections we have n * n-1 * ... * n-(r-1) denoted nPr
 */
unsigned long int nPr(int n, int r)
{
    if(r == 0)
    {
        return 0;
    }    
    unsigned long int P = 1;
    for(int i = 0; i < r; ++i)
    {
        P *= n-i; 
    }
    return P;
}

/*
    Permutations without reptition can be alternately defined as the number of possible sequences of elements from subsets of length r.
    If C is the number of subsets of length r, then the possible sequences for the subsets of length r, is r! (r == n).
    C * r! = n * n-1 * ... * n-(r-1)
    C = (n * n-1 * ... * n-(r-1)) / r!
    
 */
unsigned long int nCr(int n, int r)
{
    if(r == 0)
    {
        return 0;
    }
    unsigned long int C = nPr(n, r) / nPr(r, r);    
    return C;
}

/*
    nCr with repitions allowed (nCr(n+(r-1), r) is counting multisets of length r.
    In other words for every selection after the first we have 1 more choice than nCr as we are not removing choices.
    For r selections we have r-1 more choices than nCr.
    Defining as nMr. 
 */
unsigned long int nMr(int n, int r)
{
    int temp = n + (r-1);
    return nCr(temp, r);    
}

