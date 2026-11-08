template <class Type>
class CustomList : public MyList<Type>
{
public:
    CustomList(int m = 10) : MyList<Type>(m) {}

    CustomList(const CustomList& obj) : MyList<Type>(obj) {}

    Type sum_ofPrime()
    {
        Type sum = 0;
        for (int i = 0; i < this->currentSize; i++)
        {
            int n = this->arr[i], j;
            for (j = 2; j < n; j++)
                if (n % j == 0) break;

            if (n > 1 && j == n) sum += n;
        }
        return sum;
    }

    Type secondMaxEven()
    {
        Type a = -1, b = -1;
        for (int i = 0; i < this->currentSize; i++)
        {
            Type n = this->arr[i];
            if (n % 2 == 0 && n > a)
            {
                if (n != a) b = a;
                a = n;
            }
            else if (n % 2 == 0 && n < a && n > b)
                b = n;
        }
        return b;
    }

    Type secondMinOdd()
    {
        Type a = 0, b = 0;
        for (int i = 0; i < this->currentSize; i++)
        {
            Type n = this->arr[i];
            if (n % 2 != 0 && (a == 0 || n < a))
            {
                if (a != 0) b = a;
                a = n;
            }
            else if (n % 2 != 0 && n > a && (b == 0 || n < b))
                b = n;
        }
        return b;
    }

    void printDuplicates()
    {
        for (int i = 0; i < this->currentSize; i++)
            for (int j = i + 1; j < this->currentSize; j++)
                if (this->arr[i] == this->arr[j])
                {
                    cout << this->arr[i] << " ";
                    break;
                }
        cout << endl;
    }

    void rotateClockwaise(int r)
    {
        int n = this->currentSize;
        if (n == 0) return;
        r %= n;

        while (r--)
        {
            Type x = this->arr[n - 1];
            for (int i = n - 1; i > 0; i--)
                this->arr[i] = this->arr[i - 1];
            this->arr[0] = x;
        }
    }

    void rotateanitclockwaise(int r)
    {
        int n = this->currentSize;
        if (n == 0) return;
        r %= n;

        while (r--)
        {
            Type x = this->arr[0];
            for (int i = 0; i < n - 1; i++)
                this->arr[i] = this->arr[i + 1];
            this->arr[n - 1] = x;
        }
    }

    ~CustomList() {}
};