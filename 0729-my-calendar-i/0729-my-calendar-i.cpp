class MyCalendar {
private:
    map<int, int> startEndMp; 
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto closerFromRight = startEndMp.lower_bound(start); 
        auto closerFromLeft = (closerFromRight == startEndMp.begin()) ? startEndMp.end() : prev(closerFromRight);
        
        if (closerFromRight != startEndMp.end() && end > closerFromRight->first) {
            return false;
        }
        
        if (closerFromLeft != startEndMp.end() && start < closerFromLeft->second) {
            return false;
        }
        
        startEndMp[start] = end;
        return true;
    }
};