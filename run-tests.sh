set -e

cpplint --quiet --recursive src
ls -1 src/*.cpp | grep -v "check_for_bst\|is_bipartite\|maximum_path_sum" | xargs --max-args 1 --max-procs 2 g++ --std=c++14
