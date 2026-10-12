class BusBooking {
public:
    int time=0,mintime=0;
    vector<string> seats;
    vector<vector<int>> cost;
    BusBooking(int n) {
        time=0;  
        mintime=0;
        seats.resize(n, string(4, '0'));
        cost.resize(n, vector<int>(4, 0));
    }
    
    void toggle(string seat) {
        string s = seat.substr(1);
        int idx = seat[0]-'A';
        int row= stoi(s)-1;
        if(seats[row][idx]=='1'){
            mintime--;
            time -= cost[row][idx];
            cost[row][idx] = 0;
            seats[row][idx] = '0';
        }else{
            mintime++;
            int c = 1;
            if (idx == 0 && seats[row][1] == '1') c = 3;
            else if (idx == 3 && seats[row][2] == '1') c = 3;
            seats[row][idx] = '1';
            cost[row][idx] = c;
            time += c;
        }
    }
    
    int getTotalTime() {
        return time;
    }
    
    int getMinTime() {
        return mintime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */