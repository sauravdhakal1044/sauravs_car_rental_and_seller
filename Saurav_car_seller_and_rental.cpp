/*
This is a simple project done by Saurav Dhakal in cpp.
This is Linux based code.
Thank you.......;
First complete the administration works before allowing customer to carry out work.
1= create price lists of cars to sell.
2= create price lists of cars to rent. 
3= create cars lists for renting.
4= set available cars and rented cars .
5= once customer rents a car register the dates and time of that customer when he/she rents car.

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <unistd.h>
#include <ctime>
using namespace std;
void display();
void administration();
void setprice();
void car_for_rent();
void display_car_rent_price();
void rented_car();
void set_car_rent_price();
void registr_date_time();
void update_avai_cars();

void current_date_time(int a, int b, int c, int d, int e, int f, string h);
void calculate_total_fare(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l);
void calculatefare(string xy);

void customer();
void checkprice();
void checkfreecar(int y, string z);
void checkfare();
void calculatefare();
void registr();
void login();
void rentcar();
void retrn_car();
int main()
{
    display();
    int i, num;
    cin >> num;
    switch (num)
    {
    case 1:
        system("clear");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Loading ";
        for (i = 0; i < 2; i++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        system("clear");
        administration();
        break;
    case 2:
        system("clear");
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "Loading ";
        for (i = 0; i < 2; i++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        system("clear");
        customer();
        break;
    default:
        cout << "Oops! You have entered worng key enter again." << endl;
        display();
        break;
    }
}
void display()
{
    system("clear");
    cout << endl;
    cout << "" << setw(25);
    cout << ""
         << "* * * * * * * * * * * * * * * * * * * * * * * * * * *" << setw(25) << endl;
    cout << ""
         << "* WELCOME TO SAURAV'S CAR SELLER AND RENTAL CENTER. *" << setw(25) << endl;
    cout << ""
         << "* * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << endl;
    cout << "Which page you wanna visit?" << endl;
    cout << "1. Administration page." << endl;
    cout << "2. Customer page." << endl;
}
void administration()
{
    system("clear");
    int a, i;
    string adminid = "admin";
    string adminpass = "1044cool";
    string ai, id, ap, pass;
    cout << "Welcome to Administration page." << endl;
    cout << "Please Enter your id and password to proceed forward." << endl;
    ofstream admin;
    admin.open("admin_id_pass.txt", ios::app);
    admin << adminid << " " << adminpass << endl;
    admin.close();
    ifstream read;
    read.open("admin_id_pass.txt");
    read >> ai >> ap;
    cout << "Please Enter your id :" << endl;
    cin >> id;
    cout << "Please Enter your password :" << endl;
    cin >> pass;
    while (id != ai && pass != ap || id == ai && pass != ap || id != ai && pass == ap)
    {
        cout << "Oops Wrong id password." << endl;
        cout << "Please try again." << endl;
        sleep(1);
        system("clear");
        cout << "Please Enter your id :" << endl;
        cin >> id;
        cout << "Please Enter your password :" << endl;
        cin >> pass;
    }
    if (id == ai && pass == ap)
    {
        system("clear");
        cout << "Welcome Admin." << endl;
        cout << "Please choose what you want to do." << endl;
        cout << "1. Set cars price." << endl;
        cout << "2. Set cars rental charge." << endl;
        cout << "3. Update available cars for rent." << endl;
        cout << "4. Set cars for rent." << endl;
        cout << "5. Register rented cars." << endl;
        cout << "6. Register car rent date and time." << endl;
        cout << "7. Goto Homepage." << endl;
    sau:
        cin >> a;
        switch (a)
        {
        case 1:
            system("clear");
            cout << "Loading ";
            for (i = 0; i < 2; i++)
            {
                cout << " - ";
                cout.flush();
                sleep(1);
            }
            system("clear");
            setprice();
            break;
        case 2:
            system("clear");
            cout << "Loading ";
            for (i = 0; i < 2; i++)
            {
                cout << " - ";
                cout.flush();
                sleep(1);
            }
            system("clear");
            set_car_rent_price();
            break;
        case 3:
            system("clear");
            cout << "Loading ";
            for (i = 0; i < 2; i++)
            {
                cout << " - ";
                cout.flush();
                sleep(1);
            }
            system("clear");
            update_avai_cars();
            break;
        case 4:
            system("clear");
            car_for_rent();
            break;
        case 5:
            system("clear");
            rented_car();
            break;
        case 6:
            system("clear");
            registr_date_time();
            break;
        case 7:
            display();
            main();
            break;
        default:
            cout << "Oops! You have entered worng key enter again." << endl;
            goto sau;
        }
    }
}
void setprice()
{
    cout << "Lets Set the price of the cars admin." << endl;
    string carname;

    int price, i;
    cout << "Enter the car name you wanna set price." << endl;
    cin >> carname;
    ofstream carname1;
    carname1.open(carname + ".txt");
    cout << "Enter the price of the car." << endl;
    cin >> price;
    carname1 << price << endl;
    cout << "Setting price ";
    for (i = 0; i < 2; i++)
    {
        cout << " - ";
        cout.flush();
        sleep(1);
    }
    cout << "Price has been set." << endl;
    sleep(1);
    administration();
}
void rented_car()
{
    system("clear");
    int a, b;
    string name;
    ofstream bo;
    bo.open("rentedones.txt", ios::app);
    cout << "enter rented car num." << endl;
    cin >> a;
    cout << "enter rented car name." << endl;
    cin >> name;
    bo << a << " " << name << endl;
    cout << "Data updated." << endl;
    cout << "Enter " << endl;
    cout << "1. Administration page." << endl;
    cout << "2. Add another rented car data." << endl;
    cout << "3. Main menu." << endl;
    cin >> b;
yes:
    if (b == 1)
    {
        system("clear");
        administration();
    }
    else if (b == 2)
    {
        system("clear");
        rented_car();
    }
    else if (b == 3)
    {
        system("clear");
        display();
        main();
    }
    else
    {
        cout << "You Entered wrong key." << endl;
        cout << "Enter again." << endl;
        goto yes;
    }
}
void update_avai_cars()
{
    system("clear");
    cout << "* * * * * * NOTE * * * * * *" << endl;
    cout << "You can over write only one time and have to go back to rented car to further update the lists." << endl;
    int a, b, i;
    string name;
    ofstream bo;
    bo.open("rentedones.txt");
    cout << "enter rented car num." << endl;
    cin >> a;
    cout << "enter rented car name." << endl;
    cin >> name;
    bo << a << " " << name << endl;
    cout << "Overwriting lists ";
    for (i = 0; i < 2; i++)
    {
        cout << " - ";
        cout.flush();
        sleep(1);
    }
    cout << "List has been overwritten." << endl;
    sleep(1);
    administration();
}
void customer()
{
    system("clear");
    int num;
    cout << "Welcome to customer page ." << endl;
    cout << "Please select whatdo you want." << endl;
    cout << "1. Buy a car." << endl;
    cout << "2. Rent a car." << endl;
    cout << "3. Check fare." << endl;
    cout << "4. Goto to homepage." << endl;
    cout << "Enter number :" << endl;
dhkl:
    cin >> num;
    switch (num)
    {
    case 1:
        int i1;
        cout << "Loading ";
        for (i1 = 0; i1 < 2; i1++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        checkprice();
        break;
    case 2:
        system("clear");
        int j;
        cout << "Loading ";
        for (j = 0; j < 2; j++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        rentcar();
        break;
    case 3:
        int k;
        cout << "Loading ";
        for (k = 0; k < 2; k++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        checkfare();
        break;
    case 4:
        int l;
        cout << "Loading ";
        for (l = 0; l < 2; l++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        display();
        main();
        break;
    default:
        cout << "Oops! You have entered worng key enter again." << endl;
        goto dhkl;
    }
}
void checkprice()
{
    system("clear");
    string carname;
    int price, price1, num;
    cout << "Welcome customer." << endl;
    cout << "Please enter the name of car to check price." << endl;
    cout << "1. ford." << endl;
    cout << "2. BMW." << endl;
    cout << "3. Ranger Rover." << endl;
    cout << "4. Creta." << endl;
    cout << "5. Kia." << endl;
    cout << "6. Toyota." << endl;
    cout << "7. Nexon." << endl;
    cin >> carname;
    ifstream getcardetail1;
    getcardetail1.open(carname + ".txt");
    getcardetail1 >> price1;
    price = price1;
    cout << "The price of the car " << carname << " is " << price << endl;
    cout << "If you wanna buy it enter 1." << endl;
    cout << "Else if you wanna check price of another car enter 2." << endl;
here:
    cin >> num;
    switch (num)
    {
    case 1:
        system("clear");
        cout << "Your bill is Rs." << price << endl;
        cout << "Thank you." << endl;
        break;
    case 2:
        checkprice();
        break;
    default:
        cout << "Oops! You have entered worng key enter again." << endl;
        sleep(2);
        system("clear");
        cout << "Please enter the valid number." << endl;
        goto here;
    }
}
void checkfare()
{
    system("clear");
    int i, num;
    cout << "Welcome customer ." << endl;
    cout << "To check your fare first set your login id and pass" << endl;
    cout << "1. Register id." << endl;
    cout << "2. Login." << endl;
top:
    cin >> num;
    switch (num)
    {
    case 1:
        registr();
        break;
    case 2:
        login();
        break;
    default:
        cout << "Oops! You have entered worng key enter again." << endl;
        goto top;
    }
}
void registr()
{
    system("clear");
    int i;
    string id, idfile;
    string pass, passfile;
    cout << "Enter id." << endl;
    cin >> id;
    ifstream getdetail;
    getdetail.open("datas.txt");
    while (getdetail >> idfile)
    {
        if (id == idfile)
        {
            cout << "This id hasbeen already taken." << endl;
            cout << "Try another one." << endl;
        }
    }
    cout << "Enter password." << endl;
    cin >> pass;
    ofstream keepdetail;
    keepdetail.open("datas.txt", ios::app);
    keepdetail << id << " " << pass << endl;
    keepdetail.close();
    cout << endl;
    cout << "Registering ";
    for (i = 0; i < 2; i++)
    {
        cout << " - ";
        cout.flush();
        sleep(1);
    }
    getchar();

    cout << endl
         << "Registration successfull." << endl;
    sleep(1);
    system("clear");
    checkfare();
}
void login()
{
    system("clear");
    int i, i1;
    int count;
    string id, id1;
    string pass, pass1;
    cout << "Welcome to login page." << endl;
    cout << "Enter your id." << endl;
    cin >> id;
    cout << "Enter your password." << endl;
    cin >> pass;
    ifstream getdetail1;
    getdetail1.open("datas.txt");
    while (getdetail1 >> id1 >> pass1)
    {
        if (id == id1 && pass == pass1)
        {
            count = 1;
            system("clear");
        }
    }
    getdetail1.close();
    if (count == 1)
    {
        string id, name, c;
        cout << "Logging in  ";
        for (i1 = 0; i1 < 2; i1++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        cout << endl;
        cout << "logged in" << endl;
        sleep(1);
        system("clear");
        cout << "Welcome user." << endl;
        cout << "Please enter your name and car id you have rented to check fare." << endl;
        cin >> name >> id;
        c = name + id;
        calculatefare(c);
    }
    else
    {
        cout << "ERROR!! Wrong id password." << endl;
        cout << "PLease check and enter again." << endl;
        sleep(1);
        login();
    }
}
void car_for_rent()
{
    system("clear");
    int id, i;
    string car_rname;
    cout << "Enter id of car." << endl;
    cin >> id;
    cout << "Enter name of car." << endl;
    cin >> car_rname;
    ofstream write;
    write.open("carrent.txt", ios::app);
    write << id << " " << car_rname << endl;
    cout << "Enter 1 to add car." << endl
         << "Enter 2 to return to main menu" << endl;
    cin >> i;
    if (i == 1)
    {
        system("clear");
        car_for_rent();
    }
    else if (i == 2)
    {
        system("clear");
        administration();
    }
}
void rentcar()
{
    system("clear");
    int id1, a, count, i, b;
    string carrent1, cn;
    ifstream read;
    read.open("carrent.txt");
    cout << "* * * * * Welcome customer. * * * * * " << endl;
    cout << "1. View car price for rent." << endl;
    cout << "2. Rent car." << endl;
    cin >> i;
    if (i == 1)
    {
        system("clear");
        display_car_rent_price();
    }
    else if (i == 2)
    {
        cout << "Enter car id." << endl;
        cout << "i.e Select num from 1 to 12." << endl;
        cin >> a;
        cout << "Enter car name." << endl;
        cout << "i.e Select car+num 1 to 12." << endl;
        cin >> cn;
        while (read >> id1 >> carrent1)
        {
            if (a == id1 && cn == carrent1)
            {
                count = 1;
                cout << "Car id name matched." << endl;
                sleep(1);
                system("clear");
            }
        }
        read.close();

        if (count == 1)
        {
            cout << "Enter which nummber car you wanna book" << endl;
            cin >> a;
            cout << "Enter its name." << endl;
            cin >> cn;
            cout << "To Book it click 1" << endl;
            cin >> b;
            if (b == 1)
            {
                checkfreecar(a, cn);
            }
        }
    }
}

void checkfreecar(int y, string z)
{
    system("clear");
    int a, count;
    string c;
    ifstream chk;
    chk.open("rentedones.txt");
    while (chk >> a >> c)
    {
        if (y == a && z == c)
        {
            count = 1;
            system("clear");
        }
    }
    chk.close();
    if (count == 1)
    {
        cout << "This car is already on rent please select another." << endl;
        sleep(1);
        system("clear");
        rentcar();
    }
    if (count == 0)
    {
        int date;
        string name;
        cout << "Your Selected Car is rented." << endl;
        sleep(2);
        system("clear");
        display();
        main();
    }
}
void registr_date_time()
{
    system("clear");
    int yr, mnth, day, hr, min, sec, i;
    string name, nameid, id, tap;
    cout << "Please enter customer name ." << endl;
    cin >> name;
    cout << "Please enter id of car the customer rented." << endl;
    cin >> id;
    nameid = name + id;
    ofstream datelists;
    datelists.open(nameid + "_dt.txt", ios::app);
    cout << "Enter the year,month and day the customer  have rented the car." << endl;
    cin >> yr >> mnth >> day;
    cout << "Enter hour minutes and second the customer have rented the car. " << endl;
    cin >> hr >> min >> sec;
    cout << "Enter am or pm." << endl;
    cin >> tap;
    datelists << yr << ' ' << mnth << ' ' << day << ' ' << hr << ' ' << min << ' ' << sec << ' ' << tap << endl;
    cout << "Registering  ";
    for (i = 0; i < 2; i++)
    {
        cout << " - ";
        cout.flush();
        sleep(1);
    }
    cout << endl;
    cout << "Registration completed." << endl;
    sleep(1);
}
void calculatefare(string xy)
{
    system("clear");
    int u, v, w, x, y, z;
    string a;
    ifstream readdate;
    readdate.open(xy + "_dt.txt");
    readdate >> x >> y >> z >> u >> v >> w >> a;
    current_date_time(x, y, z, u, v, w, a);
}
void current_date_time(int a, int b, int c, int d, int e, int f, string h)
{
    system("clear");
    string tap;
    tap = h;
    int t2, hr2, min2, sec2, day2, yr2, mnth2;
    int t1, hr1, min1, sec1, day1, yr1, mnth1;
    time_t as = time(NULL);
    struct tm *rtime;
    rtime = localtime(&as);
    hr1 = rtime->tm_hour;
    min1 = rtime->tm_min;
    sec1 = rtime->tm_sec;
    yr1 = rtime->tm_year + 1900;
    mnth1 = rtime->tm_mon + 1;
    day1 = rtime->tm_mday;
    yr2 = a;
    mnth2 = b;
    day2 = c;
    min2 = e;
    sec2 = f;
    if (h == "am")
    {
        hr2 = d;
    }
    else if (h == "pm")
    {
        hr2 = d + 12;
    }
    calculate_total_fare(yr1, yr2, mnth1, mnth2, day1, day2, hr1, hr2, min1, min2, sec1, sec2);
}
void calculate_total_fare(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l)
{
    system("clear");
    int total_fare, aa, ad, p, i1, j1;
    int id1;
    int m, n, o, q, r, s;
    m = a - b;
    n = c - d;
    o = e - f;
    q = g - h;
    r = i - j;
    s = k - l;
    string carname, ab, ac;
    ifstream readprice;
    cout << "Enter car name." << endl;
    cin >> carname;
    readprice.open(carname + ".txt");
    readprice >> aa >> ab >> ac >> ad;
    p = ad;
    cout << p << endl;
    sleep(2);
    system("clear");
    total_fare = m * p * 12 * 30 + n * p * 30 + o * p + q * p / 24 + r * p / 3600;
    cout << "Your fare to pay is: Rs -" << total_fare << endl;
    sleep(2);
    cout << "Enter 1 to pay fare and return car." << endl;
    cin >> i1;
    if (i1 == 1)
    {
        cout << "Returning car ";
        for (j1 = 0; j1 < 2; j1++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        cout << endl;
        cout << "Bill paid and Car returned." << endl;
        cout << "Thank you. " << endl;
        cout << "Please visit again." << endl;
        sleep(1);
    }
    administration();
}
void set_car_rent_price()
{
    system("clear");
    ofstream glists;
    ofstream cardetail;
    int id, cars_price, b, i;
    string car_name, a;
    a = "Rs.";
    cout << "Enter car id." << endl;
    cin >> id;
    cout << "Enter car name." << endl;
    cin >> car_name;
    cout << "Enter cars rent price." << endl;
    cin >> cars_price;
    cardetail.open(car_name + ".txt");
    cardetail << id << ' ' << car_name << ' ' << a << cars_price << endl;
    cardetail.close();
    glists.open("car_rent_price.txt", ios::app);
    glists << id << " " << car_name << " " << a << ' ' << cars_price << endl;
    cout << "Updating list  ";
    for (i = 0; i < 2; i++)
    {
        cout << " - ";
        cout.flush();
        sleep(1);
    }
    cout << endl;
    cout << "List updated." << endl;
    sleep(1);
    cout << "Enter the number to proceed forward. " << endl;
    cout << "1. Administration page." << endl;
    cout << "2. Add another car rent price." << endl;
    cout << "3. Main menu." << endl;
fk:
    cin >> b;
    if (b == 1)
    {
        system("clear");
        cout << "Loading ";
        for (i = 0; i < 2; i++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        administration();
    }
    else if (b == 2)
    {
        system("clear");
        set_car_rent_price();
    }
    else if (b == 3)
    {
        system("clear");
        cout << "Loading ";
        for (i = 0; i < 2; i++)
        {
            cout << " - ";
            cout.flush();
            sleep(1);
        }
        cout << endl;
        display();
        main();
    }
    else
    {
        cout << "You Entered wrong key." << endl;
        cout << "Enter again." << endl;
        goto fk;
    }
}
void display_car_rent_price()
{
    system("clear");
    int i;
    cout << "Displaying list  ";
    for (i = 0; i < 2; i++)
    {
        cout << " - ";
        cout.flush();
        sleep(1);
    }
    cout << endl;
    string lists;
    ifstream display;
    display.open("car_rent_price.txt");
    while (display.eof() == 0)
    {
        getline(display, lists);
        cout << lists << endl;
    }
    sleep(5);
    cout << "Enter any key to return to menu." << endl;
    getchar();
    rentcar();
}