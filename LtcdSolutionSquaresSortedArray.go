func sortedSquares(A []int) []int {
    // handle empty array case
    if len(A) == 0 {
        return A
    }
    
    // negate all negative numbers
    for i := 0; i < len(A) && A[i] < 0; i++ {
        A[i] = -A[i]
    }
    
    // sort numbers using the upper 16 bits of the numbers as storage
    for i, j, k := 0, len(A)-1, len(A)-1; k >= 0; k-- {
        lo, hi := A[i] & 0xffff, A[j] & 0xffff
        
        if lo < hi {
            A[k] = A[k] | (hi << 16)
            j--
        } else {
            A[k] = A[k] | (lo << 16)
            i++
        }
    }
    
    // calculate squares using the upper 16 bits from the numbers
    for i := 0; i < len(A); i++ {
        A[i] = (A[i] >> 16) * (A[i] >> 16)
    }
    
    // return original array
    return A
}