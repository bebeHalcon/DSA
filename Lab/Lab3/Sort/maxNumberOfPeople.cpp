#include<iostream>
#include<vector>

using namespace std;

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());
    int i = 0, j = 0, count = 0;
    while(i < rooms.size() && j < people.size()){
        if (abs(rooms[i]-people[j]) <= k){
            count++;
            i++;
            j++;
        }
        else if (rooms[i] < people[j] - k) i++;
        else j++;
    }
    return count;
}

int main(){

    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;

    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for(int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for(int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << "\n" << maxNumberOfPeople(rooms, people, k) << '\n';

    // Testcase 1
    // 10 10 1000
    // 18 59 71 65 97 83 80 68 92 67
    // 59 5 65 15 42 81 58 96 50 1

    // 10

    // Testcase 2
    // 3 4 5
    // 30 60 75
    // 57 45 80 65

    // 2
}















