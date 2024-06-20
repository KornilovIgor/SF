#include "User.h"
void ChatMenu(vector<Person>& A, vector<Person::Chat>& B, string email_)
{
    char operat = '0';

    string Sender = email_;
    cout << "Your name: " << Sender << endl;


    string Receiver;
    string Message;
    bool m = false;//счетчик окончания чата
    while (operat != '3')
    {
        cout << "Choose number: " << endl << "1 - to write text" << endl << "2 - History " << endl << "3 - Exit to main Menu" << endl;
        cin >> operat;

        switch (operat)
        {
        case '1':
            cout << "if you want to finish Chat, send message 'end'" << endl;
            while (m== false) {
                GetMessage(B);
                Send_Message(Sender);
                cout << "Choose a reciever(email):";
                cin >> Receiver;
                if (find_email(Receiver) == 0)
                {
                    cout << "Enter a message:";
                    Send_Message(Receiver);
                    cin >> Message;
                    Send_Message(Message);
                    if (Message == "end") { m = true;  break; };

                    INSERT_INTO_history_data(Sender, Receiver, Message);
                }
                else { cout << "This receiver is unregistered" << endl; break; };
            };
            break;
        case '2':
            cout << "Choose receiver:" << endl;
           
            cin >> Receiver;

            show_history(Sender, Receiver);
            break;
        default:

            std::cout << "You entered wrong number" << std::endl;
            std::cout << std::endl;
            break;

        };


    };
};
