# Bubble Sort

def main():
    string_list = input('Enter a list of items to sort: ')
    lst = string_list.split()
    algo = input("Which sorting algorithm do you want to run? ")
    if algo in "selection":
        selection_sort(lst)
    elif algo in "insertion":
        insertion_sort(lst)
    elif algo in "bubble":
        bubble_sort(lst)
    else:
        print("I did not understand")



def bubble_sort(lst):
    # Loop through each element and compare it to the element on the right
    # If element is greater, then swap,
    # Repeat
    print("Running bubble sort....")
    sorted = False
    while not sorted:
        sorted = True
        for i in range(len(lst) - 1):
            if lst[i] > lst[i + 1]:
                lst[i], lst[i + 1] = lst[i + 1], lst[i]
                sorted = False
        print(" ".join(lst))

def insertion_sort(lst):
    # Loop through each element starting at index 1
    # At each element, insert the element into the sorted portion

    print("Running insertion sort....")
    for i in range(1, len(lst)):
        j = i - 1
        key = lst[i]
        while j >= 0 and lst[j] > key:
            lst[j + 1] = lst[j]
            j -= 1
        
        lst[j + 1] = key
        print(" ".join(lst))

def selection_sort(lst):
    # Loop through each element
    # Look for the smallest element and place it at the beginning of the non sorted section

    print("Running selection sort...")
    for i in range(len(lst) - 1):
        min = lst[i]
        for j in range(i, len(lst)):
            if lst[j] < min:
                min = lst[j]
                idx = j

        if min != lst[i]:
            lst[i], lst[idx] = lst[idx], lst[i]
        print(" ".join(lst))
        

if __name__ == "__main__":
    main()