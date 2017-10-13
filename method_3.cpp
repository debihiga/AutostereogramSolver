#include "solver.h"
#include "image.h"

void Solver::method_3() {

    max_disparity = get_max_disparity();
    if(max_disparity!=-1) {
        get_disparity_map();
    }
}
