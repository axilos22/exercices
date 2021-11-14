#include <iostream>
#include <string>
#include <vector>

#include "position.hpp"

using namespace std;

enum TestCase
{
    None,
    OneD_int_create,
    OneD_int_distance,
};

enum RetCode
{
    Ok,
    Default,
    Error
};

int oned_int_create(int position) {
    Position1D<int> test_pose(999);
    cout << "Created 1D Position x= " << test_pose.GetX() << endl;
    return Ok;
}

int oned_int_distance(int pos1, int pos2) {
    Position1D<int> test_pose(pos1), other_pose(pos2);
    auto distance = test_pose.ComputeDistance(other_pose);
    cout << "Computing distance between " 
    << test_pose.GetX() << " and "
    << other_pose.GetX() << " = "
    << distance << endl;
    if (distance == pos1 - pos2)
    return Ok;
    else
    return Error;
}

int main(int argc, char *argv[])
{
    int ret_code = Default;
    std::string current_exec_name = argv[0];
    std::vector<std::string> all_args;

    if (argc > 1)
    {
        all_args.assign(argv + 1, argv + argc);
        int test_case = stoi(all_args.at(0));
        switch (test_case)
        {
        case OneD_int_create:
        {
            ret_code = oned_int_create(999);
            break;
        }
        case OneD_int_distance:
        {
            ret_code = oned_int_distance(999, 567);
            break;
        }
        default:
        {
            cout << "Unexpected test case provided: " << test_case << endl;
            break;
        }
        }
    }
    else
    {
        cout << "empty run" << endl;
        return ret_code;
    }
    return ret_code;
}
