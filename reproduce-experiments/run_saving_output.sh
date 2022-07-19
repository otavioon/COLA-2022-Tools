function run_saving() {
    bash -x $1 2>&1 | tee ../../outputs/$1.out
}
