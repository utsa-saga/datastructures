public class Array {
    private int[] arr;

    public Array(int[] arr) {
        this.arr = arr;
    }

    public void insert(int value, int index) {
        if (index < 0 || index > arr.length) {
            System.out.println("Invalid index. ");
            return;
        }

        int[] newarr = new int[arr.length + 1];

        for (int i = 0, j = 0; i < (arr.length + 1); i++) {
            if (i == index) {
                newarr[i] = value;
            } else {
                newarr[i] = arr[j];
                j++;
            }
        }
        arr = newarr;
    }

    public boolean search(int value) {
        for (int i = 0; i < arr.length; i++)
        {
            if (arr[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    public void delete(int value) {
        if (!search(value))
        {
            System.out.println("No such element in the array. ");
            return;
        }
        int[] newarr = new int[arr.length - 1];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] != value) {
                newarr[i] = arr[i];
            } 
        }
        arr = newarr;
    }

    public void printarr() {
        System.out.println("Array: " + java.util.Arrays.toString(arr));
    }

    public static void main(String[] args) {
        int[] arr = {75, 22, 51, 40, 15};
        Array enrollment = new Array(arr);

        enrollment.printarr();
        enrollment.insert(50, 2);
        enrollment.printarr();
        enrollment.delete(40);
        enrollment.printarr();
    }
}