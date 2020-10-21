from math import ceil, floor

X = []
Y = []

def get(A, indexes=[]):
  s = ""
  for i in indexes:
    assert(i <= len(A))
    s += "A[{}]= {}\n".format(i, A[i-1])
  print(s)


def InsertionSort(a, out=(-1,-1)):
    for j in range(1, len(a)):
        if callBack[0] > 0:
          print("j: {}, A[{}]= {}".format(out[0], out[1], a[out[1]-1]))
          return
               
        
        key = a[j]
        i = j - 1

        while i >= 0 and a[i] > key:
            a[i + 1] = a[i]
            i -= 1

        a[i + 1] = key


def Merge(a, p, q, r, out=-1):
    m = q - p + 1
    n = r - q
    left = []
    right = []

    for i in range(1, m + 1):
        left.append(a[p + i - 1])

    for j in range(1, n + 1):
        right.append(a[q + j])

    left.append(1e3000)
    right.append(1e3000)
    i = 0
    j = 0

    for k in range(p, r + 1):
        if left[i] <= right[j]:
            a[k] = left[i]
            i += 1
        else:
            a[k] = right[j]
            j += 1

    if out > -1:
      print("A[{}]= {}".format(out, a[out-1]))

def MergeSort(a, p, r):
    if p < r:
        q = (p + r) / 2
        MergeSort(a, p, q)
        MergeSort(a, q + 1, r)
        Merge(a, p, q, r)

def _parent(i):
  return floor((i-1)/2)

def _left(i):
  return 2*i + 1

def _right(i):
  return 2*i + 2

def Parent(i):
  return i/2

def Left(i):
  return 2*i

def Right(i):
  return 2*i + 1

def _maxheapify(A, hs, i, out=-1):
  l = _left(i)
  r = _right(i)

  largest = -1

  if l <= hs and A[l] > A[i]:
    largest = l
  else:
    largest = i

  if r <= hs and A[r] > A[largest]:
    largest = r
  
  if largest != i:
    temp = A[i]
    A[i] = A[largest]
    A[largest] = temp
    _maxheapify(A, hs, largest, out)

def BuildMaxHeap(A):
  hs = len(A)
  
  for i in range((len(A)//2)+1, 0, -1):
    _maxheapify(A, hs-1, i-1)

def _partition(a, p, r, out=-1):

    x = a[r]
    i = p - 1
    
    for j in range(p, r):
        if a[j] <= x:
            i += 1
            temp = a[i]
            a[i] = a[j]
            a[j] = temp
    
    temp = a[i + 1]
    a[i + 1] = a[r]
    a[r] = temp

    if out > -1:
      print("A[{}]= {}".format(out, a[out-1]))
    
    return i + 1

def Partition(a, p, r, out=-1):
  _partition(a, p-1, r-1, out)

def _quickSort(a, p, r):

    if p < r:
        q = _partition(a, p, r)
        _quickSort(a, p, q - 1)
        _quickSort(a, q + 1, r)

def QuickSort(a, p, r):
  _quickSort(a, p-1, r-1)

