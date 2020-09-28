#include <iostream>

using namespace std;

void Initial();
int AddAfter(int, int);
int AddBefore(int, int);
void Show();
int Del(int);
bool Empty();
void DelAll();

struct LIST {
    int info;
    LIST* next;
};

LIST* head, * Prey;


int main() {
    Initial();
    int num, point;
    char option;
    do {
        cout << endl << "1.Adding" << endl << "2.Remove" << endl << "3.List output" << endl << "0.Exit" << endl;
        cin >> option;
        switch (option) {

            case '1':
                int subOption;
                cout << "1.Add before element" << endl << "2.Add after element" << endl;
                cin >> subOption;

                switch (subOption) {
                    case 1:
                        cout << endl << "Before which element to add: ";
                        cin >> point;
                        cout << "The value of the added element: " << endl;
                        cin >> num;
                        AddBefore(num, point);
                        cout << endl << "Item added to the list" << endl;
                        break;
                    case 2:
                        cout << endl << "After which element to add: ";
                        cin >> point;
                        cout << "The value of the added element: " << endl;
                        cin >> num;
                        AddAfter(num, point);
                        cout << endl << "Item added to the list" << endl;
                }
                break;
            case '2':
                if (Empty())
                    cout << endl << "The list is empty" << endl;
                else {
                    cout << endl << "The element to be removed" << endl;
                    cin >> num;

                    Del(num);
                    cout << endl << "Items removed" << endl;
                }
                break;
            case '3':
                if (Empty())
                    cout << endl << "The list is empty" << endl;
                else
                    Show();
                break;
            case '0':
                DelAll();
                break;
            default:
                cout << endl << "A error" << endl;
                break;
        }

    } while (option != '0');
    cin.get();
}

LIST* Search(int num) {
    Prey = head;
    LIST* tmp = head->next;

    while (tmp != NULL && tmp->info != num) {
        Prey = tmp;
        tmp = tmp->next;
    }

    return tmp;
}

int Del(int num) {
    LIST* current = Search(num);

    if (current != NULL) {
        Prey->next = current->next;
        delete current;

        return 1;
    }

    return 0;
}

void Initial() {
    head = new LIST;
    head->next = NULL;
}

bool Empty() { return (head->next == NULL); }

void DelAll() {
    LIST* ptr1, * ptr2;// рабочие указатели
    ptr1 = head;
    ptr2 = ptr1->next;// ptr2 опережает ptr1

    while (ptr2 != NULL) {
        ptr1 = ptr2;
        ptr2 = ptr1->next;
        delete ptr1;
    }

    delete head;
}

void Show() {
    LIST* tmp = head->next;
    cout << endl << "List items:" << endl;

    while (tmp != NULL) {
        cout << tmp->info << " ";
        tmp = tmp->next;
    }

    cout << endl;
}

int AddAfter(int num, int point) {
    if (Empty()) {
        LIST* tmp = new LIST;
        head->next = tmp;
        tmp->info = num;
        tmp->next = NULL;

        return 1;
    }

    LIST* current = Search(point);

    if (current != NULL) {
        LIST* tmp = new LIST;
        tmp->next = current->next;
        current->next = tmp;
        tmp->info = num;

        return 1;
    }

    return 0;
}

int AddBefore(int num, int point) {
    LIST* current = Search(point);

    if (current != NULL) {
        LIST* tmp = new LIST;
        Prey->next = tmp;
        tmp->next = current;
        tmp->info = num;

        return 1;
    }

    return 0;
}