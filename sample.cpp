#include <iostream>
#include <utility>
#include <string>
#include <functional>
#include <vector>
#include <unordered_map>

using namespace std;
using namespace placeholders;


// sample test functions
class Print{

  public:
    static void print21(string s1){ cout<<"func1 with string param : "<<s1<<endl;}
    static void print22(string s1){ cout<<"func2 with string param : "<<s1<<endl;}

    static void print1() { cout << "no params" << endl; }

};

class EventBus {
public:

    template<typename Function>
    void add(string ev_name, Function&& exec) {
        events_[ev_name].push_back(make_shared<Event>(ev_name, exec));
    }

    void invoke(string ev_name, string arg) {
        if (!events_.count(ev_name)) {
            return; // no events were registered with ev_name
        }

        auto ev_list = events_[ev_name];
        for (auto& e : ev_list) {
            cout << "\n" << e->name_;
            e->arg_ = arg; // update the argument.
            e->fn_();
        }
    }

private:
    struct Event {
        template<typename Function>
        Event(string s, Function&& exec) 
        {
            name_ = s;
            fn_ = bind(std::forward<Function>(exec), ref(arg_));
        }
        string name_;
        function<void()> fn_;
        string arg_;
        bool cancel;
    };

    unordered_map<string, vector<shared_ptr<Event>>> events_;
};


//driver
int main() {
  
    EventBus cb;
    cb.add("ev2", &Print::print21);
    cb.add("ev2", &Print::print22);
    //cb.invoke("bla");
    cb.invoke("ev2","bla");

}