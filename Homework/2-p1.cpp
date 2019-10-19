#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Date {
    protected:
        int year;
        int month;
        int day;
    public:
        Date(int y, int m, int d) {
            year = y;
            month = m;
            day = d;
        }
        int getYear() {
            return year;
        }
        int getMonth() {
            return month;
        }
        int getDay() {
            return day;
        }
        void printDate() {
            printf("%d/%d/%d", year, month, day);
        }
};
class Time {
    protected:
        int hour;
        int minute;
        int second;
    public:
        Time(int h, int m, int s) {
            hour = h;
            minute = m;
            second = s;
        }
        int getHour() {
            return hour;
        }
        int getMinute() {
            return minute;
        }
        int getSecond() {
            return second;
        }
        void printTime() {
            printf("%d:%d:%d", hour, minute, second);
        }
};
class Schedule : public Date, public Time {
    protected:
        int ID;
    public:
        Schedule(int id, int year, int month, int day, int hour, int minute, int second) 
        : Date(year, month, day), Time(hour, minute, second){
            ID = id;
        }
        bool operator < (const Schedule & s2) const;
        void display() {
            printf("The urgent schedule is No.%d: %d/%d/%d %d:%d:%d\n",
                    ID, year, month, day, hour, minute, second);
        }
};

bool Schedule::operator < (const Schedule & s2) const {
    return this->year != s2.year     ? this->year < s2.year
        :  this->month != s2.month   ? this->month < s2.month
        :  this->day != s2.day       ? this->day < s2.day
        :  this->hour != s2.hour     ? this->hour < s2.hour
        :  this->minute != s2.minute ? this->minute < s2.minute
        :  this->second < s2.second;
}
int main()
{
    int ID;
    vector<Schedule> v;
    while(cin >> ID && ID != 0) {
        int year, month, day, hour, minute, second;
        scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
        v.push_back(Schedule(ID, year, month, day, hour, minute, second));
    }
    sort(v.begin(), v.end());
    v[0].display();
    return 0;
}