#include <iostream>
using namespace std;


template <typename  T>
struct Node
{
    T data;
    Node<T>* next;
};

bool isEmpty(Node<int> *f)
{
    return (f == nullptr) ? true : false;
}

int lastData(Node<int>* f)
{
    int res;
    Node<int>* aux = f;
    while (aux != nullptr)
    {
        if (aux->next == nullptr)
            res = aux->data;
        aux = aux->next;
    }
    return res;
}

int getLength(Node<int>* f)
{
    int i = 0;
    Node<int>* aux = f;
    while (aux != nullptr)
    {
        i++;
        aux = aux->next;
    }
    return i;
}

Node<int>* getPrev(Node<int>* node, Node<int>* f)
{
    Node<int>* aux = f;
    Node<int>* aux2;
    while (aux->next != nullptr)
    {
        aux2 = aux;
        aux = aux->next;
        if (aux == node)
        {
            return aux2;
        }
    }
    return nullptr;
}

void insertData(Node<int>* f,int data, int pos)
{
    Node<int>* aux = f;
    Node<int>* aux2 = new Node<int>;
    aux2->data = data;
    aux2->next = nullptr;

    if (pos == 0) {
        f = aux2;
        f->next = aux;
    }
    else {
        int count = 0;
        Node<int>* prev = new Node<int>;

        while (count != pos) {
            if (count == (pos - 1)) {
                prev = aux;
            }
            aux = aux->next;
            count++;
        }
        prev->next = aux2;
        aux2->next = aux;
    }
}

void printData(Node<int>* f)
{
    Node<int>* aux = f;
    while (aux != nullptr)
    {
        if (aux->next == nullptr)
            cout << aux->data;
        else
            cout << aux->data << ", ";
        aux = aux->next;
    }
}

int deleteData(Node<int>* f, int pos)
{
    Node<int>* aux = f;
    for (int i = 0; i < pos - 1; i++)
        aux = aux->next;
}

void deleteList(Node<int>* f)
{

}

int main()
{
    Node<int>* firstNode = nullptr;
    int m;
    while (true)
    {
        cout << "[1]Vacia\n[2]Inserta\n[3]Elimina\n[4]Imprimir\n[5]Anula\n[6]Salir" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
        {
            if (isEmpty(firstNode))
                cout << "La lista esta vacia" << endl;
            else
                cout << "La lista esta vacia" << endl;
        }break;
        case 2:
        {
            int data, pos;
            cout << "Digite el dato que deseas insertar" << endl;
            cin >> data;
            cout << "Digite la posicion en la que deseas insertarlo" << endl;
            cin >> pos;
            if (getLength(firstNode) <= pos)
                cout << "Posicion invalida" << endl;
            else
                cout << "Se inserto el dato correctamente" << endl;

        }break;
        case 3:
        {
            int pos;
            cout << "Digite la posicion de la que deseas eliminar" << endl;
            cin >> pos;
            deleteData(firstNode, pos);
        }break;
        case 4:
        {
            printData(firstNode);
        }break;
        case 5:
        {
            deleteList(firstNode);
        }break;
        case 6:
        {
            return 1;
        }break;
        }
        system("pause");
        system("cls");
    }
    return 1;
}