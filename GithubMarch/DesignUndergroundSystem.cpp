class UndergroundSystem {
public:
 
    //here we are taking a map DS to save the journey details of the customer
    map<int,pair<int,string>> entryDetails; /*here key will be the ID, as ID is unique in the question as well,
                                              and pair will be the value in which we have int as time and string as station Name*/ 
 
    //here we are taking another map DS to save the total Traveling time between two stations
    map<pair<string,string>,int> totalTravelTime;/*here pair will be the key, using which we will get value 
                                                total Travel Time of type int*/
 
    //here we are taking 3rd map DS to save or to keep track of number of customers who travelled in the exact same path
    map<pair<string,string>,int> noOfCustomers;
 
    UndergroundSystem() {
 
    }
 
    void checkIn(int id, string stationName, int t) {
        entryDetails[id] = {t,stationName};//saving the ticket details of customer while purchasing!
    }
 
    void checkOut(int id, string stationName, int t) {//only here we will check the tickets!
        double diff = (t-entryDetails[id].first); // here we are calculating the time difference between stations
 
        totalTravelTime[{entryDetails[id].second,stationName}] += diff; //here we are adding the time difference
        noOfCustomers[{entryDetails[id].second,stationName}]++;/*here we are incrementing the number of customer 
                                                                who who travelled in the exact same path*/
 
        entryDetails.erase(id);//here we are erasing the details as we are checking out!
    }
 
    double getAverageTime(string startStation, string endStation) {
        return ((double)totalTravelTime[{startStation,endStation}])/noOfCustomers[{startStation,endStation}];/*here we are 
        simply deviding the total travel time with total number of customers who travelled in that exact same path*/
    }
};
 
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */