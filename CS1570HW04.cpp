//Michael Turner
//Duedate: 10/16/2023
//file: CS1570HW04.cpp
//Assignment: HW4
//Purpose: This program walks a anxious character through their visit at the dentist

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    char mainMenuChoice;
    double bill = 0.00;
    int anxiety;
    char waitingRoom;
    char recceptionist;
    char dentistRoom;
    int candy;
    string services;
    cout << "set Jamie's initial anxiety level with a value between 0-10: ";
    cin >> anxiety;
    while (anxiety < 0 || anxiety >10) {//check valid input
        cout << "Invalid range. Please enter value 0-10 " << endl;
        cin >> anxiety;
    }
    do {
        anxiety = anxiety < 0 ? anxiety = 0 : (anxiety > 10 ? anxiety = 10 : anxiety = anxiety); //Ternary operator for anxiety to always be between 0 and 10
        cout << anxiety<< endl;
        cout << "1. Choose a waiting room activity \n2. Speak with the receptionist \n3. Enter the dentist's room \n4. Consider leaving (Jamie's nerves might get the better of him!)"<< endl;
        cin >> mainMenuChoice;
        switch (mainMenuChoice) {
        case '1':// waiting room activities
            cout << "1. Read a comic book \n2. Play a handheld video game \n3. Watch a cartoon on TV \n4. Doodle on a piece of paper \n5. Do nothing" << endl;
            cin >> waitingRoom;
            switch (waitingRoom) {
            case '1': //comic book
                cout << "Jamie picks up a colorful comic book from the waiting area. The adventure-filled pages are complimentary for waiting patients, adding no additional charge to the final bill. This option decreases anxiety by 2, as reading distracts and calms Jamie." << endl;
                anxiety -= -2;
                services += "\nDoodle on a piece of paper: $20.00";
                break;
            case '2'://video game
                cout << "Jamie rents a gameboy from the receptionist, unaware that this comfort comes with a minor cost of $50 fee to his bill. This option decreases anxiety by 3, as the game provides a deep diversion." << endl;
                anxiety -= 3;
                bill += 50.00;
                services += "\nGameboy: $50.00";
                break;
            case '3'://Cartoon
                cout << "Jamie comfortably settles into a chair, immersing himself in the cartoon, thankful for the complimentary entertainment. This option decreases anxiety by 2, as the light-hearted content eases his nerves." << endl;
                anxiety -= 2;
                break;
            case '4'://Doodle
                cout << "Jamie grabs a drawing kit from the receptionist, informed that there’s a small $20 charge for using the kit. This option increases anxiety by 1, as the unexpected charge causes a minor spike in his anxiety." << endl;
                anxiety += 1;
                bill += 20.00;
                services += "\nDrawing kit: $20.00";
                break;
            case '5'://nothing
                cout << "Jamie decides to sit quietly in a plush armchair, lost in his thoughts, without engaging in any activity. This option incurs a comfort fee of $7.20. Also, Jamie’s anxiety increases by 1. The tranquility, although relaxing, forces Jamie to ruminate on the impending visit, making him slightly more anxious." << endl;
                anxiety += 1;
                bill += 7.20;
                services += "\nComfort fee: $7.20";
                break;
            default:
                cout << "Invalid option" << endl;
            }
            break;
        case '2'://speaking with the receptionist
            cout << "1. What will the dentist do? \n2. How long will it take? \n3. Can I have a candy after?" << endl;
            cin >> recceptionist;
            switch (recceptionist) {
            case '1': ////what will the denstist do
                cout << "The receptionist explains the standard procedures. No direct charge for this information. Jamie’s anxiety increases by 1, as hearing about procedures makes him slightly nervous." << endl;
                anxiety += 1;
                break;
            case '2'://How long will it take
                cout << "The receptionist informs Jamie that the procedure usually takes about 30 minutes at no additional cost. This decreases Jamie’s anxiety by 1, as knowing this info eases Jamie’s worries a bit." << endl;
                anxiety -= 1;
                break;
            case '3'://Can I have a candy after?
                cout << "The receptionist smiles and shows Jamie a jar of assorted candies. " << endl;
                cout << "How many candies would you like ? (0 - 5)";
                cin >> candy;
                while (candy > 5 || candy < 0) {
                    cout << "Invalid number. Please enter number (0-5): ";
                    cin >> candy;
                }for (int i = 0; i == candy; ++i) {
                    bill += 10.00;
                    services += "\nCandy: $10.00";
                }
                anxiety = candy >= 3 ? anxiety -= 4 : (candy == 2 ? anxiety -= 2 : anxiety = anxiety); // ternary operator for candy and anxiety
                break;
            default:
                cout << "Invalid option" << endl;
            }
            break;
        case '3'://Entering the dentists room
                cout << "1. speak with the dentist \n2. Choose a toy to hold during the visit \n3. Start the dental procedure" << endl;
                cin >> dentistRoom;
                switch (dentistRoom) {
                case '1': //Speak with the dentist
                    cout << "Jamie and the dentist engage in a light conversation, with the dentist explaining what will happen during the visit. This action costs Jamie $40 but lowers his anxiety by 2, as understanding the process can be reassuring." << endl;
                    anxiety -= 2;
                    bill += 40.00;
                    services += "\nSpeaking with the dentist: $40.00";
                    break;
                case '2'://Choose a toy
                    cout << "Jamie chooses a soft plush toy which makes him feel safer. This costs him $32 but lowers his anxiety by 3." << endl;
                    anxiety -= 3;
                    bill += 32.00;
                    services += "\nSoft plush toy: $32.00";
                    break;
                case '3'://start operation
                    break;
                default:
                    cout << "Invalid option" << endl;
                }
                if (anxiety > 5) { //go back to main menu if Jamie is too anxious
                    cout << "Jamie is too anxious, go back to the lobby." << endl;
                    break;
                }
                cout << "1. Standard checkup \n2. Teeth Cleaning \n3. Cavity filling \n4. Specialist consultation " << endl;
                cin >> dentistRoom;
                switch (dentistRoom) {
                case '1': //Standard check up
                    cout << "Jamie gets a standard dental checkup for $50.  This increases Jamie’s anxiety by 1 since a standard checkup is fairly routine." << endl;
                    anxiety += 1;
                    bill += 50.00;
                    services += "\nStandard dental checkup: $50.00";
                    mainMenuChoice = '4';
                    break;
                case '2'://Teeth Cleaning
                    cout << "Jamie opts for teeth cleaning for $75. This increases Jamie’s anxiety by 2 since the sensation and sound of the cleaning tools slightly raise his anxiety. " << endl;
                    anxiety += 2;
                    bill += 75.00;
                    services += "\nTeeth Clening: $75.00";
                    mainMenuChoice = '4';
                    break;
                case '3'://Cavity filling
                    cout << "Cavity filling: A cavity is detected and filled during the visit for $100. This increases Jamie’s anxiety by 3 since the filling procedure can be quite nerve-wracking." << endl;
                    bill += 100.00;
                    services += "\nCavity filling: $100.00";
                    anxiety += 3;
                    mainMenuChoice = '4';
                    break;
                case '4'://Specialist consultation:
                    cout << "Jamie needs advice from a specialist and gets a consultation for $300. This increases Jamie’s anxiety by 2 since consulting a specialist implies a potential issue, which can make Jamie more anxious about his dental health." << endl;
                    anxiety += 2;
                    bill += 300.00;
                    services += "\nSpecialist consultation: $300.00";
                    mainMenuChoice = '4';
                    break;
                default:
                    cout << "Invalid option" << endl;
                }

            break;
        case '4': // Exit the office
            cout << "If Jamie’s anxiety is too high, he might decide he’s not ready to see the dentist. This decreases Jamie’s anxiety by 3, as leaving brings immediate relief, even if it’s only a temporary solution. However, Jamie will incur a “Missed Appointment Fee” for not proceeding with the scheduled visit ($250)." << endl;
            anxiety -= 3;
            bill += 250.00;
            services += "\nMissed apointment fee: $20.00";
            break;
        default:
            cout << "Invalid input" << endl;
        }
    } while (mainMenuChoice != '4');
    cout << "Jamie left the dentist office" << endl;
    if (anxiety >= 6) {//IF ELSE statements to display Jamie's final emotional state
        cout << "Jamie's emotional state is Very Anxious" << endl;
    }
    else if (anxiety >= 1) {
        cout << "Jamie's emotional state is Nervous" << endl;
    }
    else if (anxiety == 0) {
        cout << "Jamie's emotional state is calm" << endl;
    }
    cout << "Billing Details: \n-------------------" << endl;
    cout << services << endl;
    cout << "----------------------\nTotal Amount Due: $" << fixed<< setprecision(2)<< bill << endl;
    return 0;
}