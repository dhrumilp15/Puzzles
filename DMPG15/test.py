
# Creates a diff array D[] for A[] and returns 
# it after filling initial values. 
def initializeDiffArray( A): 
    n = len(A) 
  
    # We use one extra space because 
    # update(l, r, x) updates D[r+1] 
    D = [0 for i in range(0 , n + 1)] 
  
    D[0] = A[0]; D[n] = 0
      
    for i in range(1, n ): 
        D[i] = A[i] - A[i - 1] 
        print("Diff array: " + str(D))
    return D 
  
  
# Does range update 
def update(D, l, r, x): 
  
    D[l] += x 
    D[r + 1] -= x 
  
  
# Prints updated Array 
def printArray(A, D): 
  
    for i in range(0 , len(A)): 
        if (i == 0): 
            A[i] = D[i] 
            print(A)
        # Note that A[0] or D[0] decides 
        # values of rest of the elements. 
        else: 
            print(str(A) + " " + str(D))
            A[i] = D[i] + A[i - 1] 
  
        print(A[i], end = " ") 
      
    print ("") 
  
  
# Driver Code 
A = [1,2,3] 
print("A: " + str(A))  
# Create and fill difference Array 
D = initializeDiffArray(A) 
  
# After below update(l, r, x), the 
# elements should become 20, 15, 20, 40 
update(D, 0, 1, 10) 
print("D after update(): " + str(D))
printArray(A, D) 
  
# After below updates, the 
# array should become 30, 35, 70, 60 
update(D, 1, 2, 20) 
update(D, 2, 2, 30) 
printArray(A, D) 