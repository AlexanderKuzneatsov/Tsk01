#include <iostream>

using namespace std;

class Node
{
public:
    Node()
    {

    };

    Node(int value, Node* pNext);
    
    ~Node();

    int value;
    Node* pNext, *head;

    int size = 0;
   


    bool why;

    void method(int value,Node * current,bool why);

    void DeleteFromEnd(int n);

    
    void SetValue(int value)
    {
        Node* current = this->head;
        why = true;
        method(value, current, why);
    }

    void GetValue( int value)
    {
        Node* current = this->head;
        why = false;
        method(value, current, why);
    }
};


Node::Node(int value, Node* pNext)
{
    this->value = value;
    this->pNext = pNext;
}

Node::~Node()
{
}

void Node::method(int value, Node* current, bool why)
{
    if (head == nullptr)
    {
        if (why == true)
        {
            head = new Node(value, pNext);
            size++;
            return;
        }
       
    }
    else
    {
        if (why == true)
        {
            while (current->pNext != nullptr)
            {
                current = current->pNext;
            }
            current->pNext = new Node(value, pNext);
            size++;
        }

        else
        {
            if (current->value == value)
            {
                cout << "Искомый элемент - " << value << " присутствует в списке" << endl;
            }
            
            else if (current->pNext == nullptr)
            {
                cout << "Элемента - " << value << " нет в списке" << endl;
            }

            else
            {
                current = current->pNext;
                method(value, current, why);
            }
           

        }
        
    }

}

void Node::DeleteFromEnd(int n)
{
    Node* current = this->head;

    Node* current2 = this->head;
    
    int j = 0;

    for (int i = 0; i < ((size - n) + 1); i++)
    {
        if (j == (size - n))
        {
            j = 0;
            Node* ptr = current->pNext;
            int a = current->value;
            for (int i = 0; i < (size - n); i++)
            {

                if (j == ((size - n) - 1 ))
                {
                    current2->pNext = ptr;
                    cout << "Элемент - " << a << " удален" << endl;
                    delete current;
                }
                
                current2 = current2->pNext;
                j++;

            }
        }
        
        current = current->pNext;
        j++;
        

        

    }

   
}

int main()
{
    setlocale(LC_ALL, "ru");
    Node first;
    first.SetValue(23);
    first.SetValue(124);
    first.SetValue(232);
    first.SetValue(132);
    first.SetValue(954);
    first.SetValue(25);
    first.SetValue(62);
    first.SetValue(26);
    first.SetValue(73);
    first.SetValue(13);
    first.SetValue(3);

    first.GetValue(7);
    first.GetValue(25);
    first.GetValue(3);
    first.GetValue(13);

    first.DeleteFromEnd(2);

    first.GetValue(13);
    first.GetValue(3);

}
