#include <iostream>
#include <string>
#include <vector>

#include "position.hpp"

using namespace std;

enum TestCase
{
    None,
    OneD_int_create,
    OneD_int_increase,
    OneD_int_decrease,
    OneD_int_distance,
    OneD_int_absDistance,
    OneD_double_distance,
};

enum RetCode
{
    Ok,
    Default,
    Error
};

int oned_int_create(int position)
{
    Position1D<int> test_pose(position);
    if (position == test_pose.GetX())
        return Ok;
    else
        return Error;
}

int oned_int_increase()
{
    Position1D<int> test_pose(123);
    test_pose.IncreaseX(10);
    if (133 == test_pose.GetX())
        return Ok;
    else
        return Error;
}

int oned_int_decrease()
{
    Position1D<int> test_pose(123);
    test_pose.DecreaseX(10);
    if (113 == test_pose.GetX())
        return Ok;
    else
        return Error;
}

int oned_int_distance(int pos1, int pos2)
{
    Position1D<int> test_pose(pos1), other_pose(pos2);
    auto distance = test_pose.ComputeDistance(other_pose);
    if (distance == pos1 - pos2)
        return Ok;
    else
        return Error;
}

int oned_int_absDistance(int pos1, int pos2)
{
    Position1D<int> test_pose(pos1), other_pose(pos2);
    auto distance = test_pose.ComputeAbsoluteDistance(other_pose);
    if (distance == abs(pos1 - pos2))
        return Ok;
    else
        return Error;
}

int oned_double_distance(double pos1, double pos2)
{
    Position1D<double> test_pose(pos1), other_pose(pos2);
    auto distance = test_pose.ComputeDistance(other_pose);
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
            ret_code = oned_int_create(999);
            break;
        case OneD_int_increase:
            ret_code = oned_int_increase();
            break;
        case OneD_int_decrease:
            ret_code = oned_int_decrease();
            break;
        case OneD_int_distance:
            ret_code = oned_int_distance(10, 20);
            break;
        case OneD_int_absDistance:
            ret_code = oned_int_absDistance(10, 20);
            break;
        case OneD_double_distance:
            ret_code = oned_double_distance(-123.456, -234.567);
            break;
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
    }
    return ret_code;
}
