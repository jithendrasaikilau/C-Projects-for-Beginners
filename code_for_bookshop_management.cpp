#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class bookshop
{
public:
    void control_panel();
    void add_book();
    void Display_book();
    void Delete_book();
    void Check_individual_book();
    void Update_book();
};

void bookshop::control_panel()
{
    cout << "Welcome to the Book shop" << endl;
    cout << endl;
    cout << "\t1.Add Book" << endl;
    cout << "\t2.Display Book" << endl;
    cout << "\t3.Check Individual Book" << endl;
    cout << "\t4.Update book" << endl;
    cout << "\t5.Delete book" << endl;
    cout << "\t6.Exit" << endl;
}

void bookshop::add_book()
{
    system("cls");
    fstream file;
    int num_copy; // Corrected variable name
    string book_name, author_name, book_id;
    cout << "\tAdd book" << endl;
    cout << "\tEnter book id" << endl;
    cin >> book_id;
    cout << "\tEnter book name" << endl;
    cin >> book_name;
    cout << "\tEnter author name:" << endl;
    cin >> author_name;
    cout << "\tEnter number of copies:" << endl; 
    cin >> num_copy;
    file.open("book.txt", ios::out | ios::app);
    file << book_id << " " << book_name << " " << author_name << " " << num_copy << endl; 
    file.close();
}

void bookshop::Display_book()
{
    system("cls");
    fstream file;
    int num_copy;
    string book_id, book_name, author_name;
    cout<<"\t All books"<<endl;
    file.open("book.txt",ios::in);
    if(!file)
    {
        cout<<"FILE NOT FOUND"<<endl;
        return;
    }
    else
    {
        cout<<"\t Book ID \t Book name \t Author name \t Number of copies"<<endl;
        file >> book_id >> book_name >> author_name >> num_copy;
        while(!file.eof())
        {
            cout<<"\t"<<book_id<<"\t"<<book_name<<"\t"<<author_name<<"\t"<<num_copy<<endl;
            file >> book_id >> book_name >> author_name >> num_copy;
        }
        file.close();
    }
}
void bookshop::Check_individual_book()
{
    system("cls");
    fstream file;
    int num_copy;
    string book_id, book_name, author_name, check_id;

    cout << "\t Check Individual Book" << endl;
    cout << "\t Enter the book id to check: ";
    cin >> check_id;

    file.open("book.txt", ios::in);

    if (!file)
    {
        cout << "FILE NOT FOUND" << endl;
        return;
    }
    else
    {
        bool found = false;
        file >> book_id >> book_name >> author_name >> num_copy;
        while (!file.eof())
        {
            if (book_id == check_id)
            {
                found = true;
                cout << "\t Book ID \t Book name \t Author name \t Number of copies" << endl;
                cout << "\t" << book_id << "\t" << book_name << "\t" << author_name << "\t" << num_copy << endl;
                break;
            }

            file >> book_id >> book_name >> author_name >> num_copy;
        }

        if (!found)
        {
            cout << "\t Book with ID " << check_id << " not found." << endl;
        }

        file.close();
    }
}
void bookshop::Update_book()
{
    system("cls");
    fstream file, temp;
    int num_copy;
    string book_id, book_name, author_name, update_id;

    cout << "\t Update Book" << endl;
    cout << "\t Enter the book id to update: ";
    cin >> update_id;

    file.open("book.txt", ios::in);
    temp.open("temp.txt", ios::out);

    if (!file)
    {
        cout << "FILE NOT FOUND" << endl;
        return;
    }
    else
    {
        bool found = false;
        file >> book_id >> book_name >> author_name >> num_copy;
        while (!file.eof())
        {
            if (book_id == update_id)
            {
                found = true;
                cout << "\t Book ID \t Book name \t Author name \t Number of copies" << endl;
                cout << "\t" << book_id << "\t" << book_name << "\t" << author_name << "\t" << num_copy << endl;
                cout << "\t Enter updated information:" << endl;
                cout << "\t Enter updated book name: ";
                cin >> book_name;
                cout << "\t Enter updated author name: ";
                cin >> author_name;
                cout << "\t Enter updated number of copies: ";
                cin >> num_copy;

                temp << update_id << " " << book_name << " " << author_name << " " << num_copy << endl;
            }
            else
            {
                temp << book_id << " " << book_name << " " << author_name << " " << num_copy << endl;
            }

            file >> book_id >> book_name >> author_name >> num_copy;
        }

        if (!found)
        {
            cout << "\t Book with ID " << update_id << " not found." << endl;
        }

        file.close();
        temp.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}
void bookshop::Delete_book()
{
    system("cls");
    fstream file, temp;
    int num_copy;
    string book_id, book_name, author_name, delete_id;

    cout << "\t Delete Book" << endl;
    cout << "\t Enter the book id to delete: ";
    cin >> delete_id;

    file.open("book.txt", ios::in);
    temp.open("temp.txt", ios::out);

    if (!file)
    {
        cout << "FILE NOT FOUND" << endl;
        return;
    }
    else
    {
        file >> book_id >> book_name >> author_name >> num_copy;
        while (!file.eof())
        {
            if (book_id != delete_id)
                temp << book_id << " " << book_name << " " << author_name << " " << num_copy << endl;

            file >> book_id >> book_name >> author_name >> num_copy;
        }
        file.close();
        temp.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");

        cout << "\t Book with ID " << delete_id << " deleted successfully." << endl;
    }
}

int main()
{
    int choice;
    char x;
    bookshop book;

    while(1)
    {
       book.control_panel();
        cout<<"\t Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                do{
                    book.add_book();
                    cout<<"Do you want to add more books? (y/n): ";
                    cin>>x;
                } while(x=='y'||x=='Y');
                break;

            case 2:
                book.Display_book();
                break;
            case 3:
                book.Check_individual_book();
                break;
            case 4:
                book.Update_book();
                break;
            case 5:
                book.Delete_book();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                exit(0);
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}