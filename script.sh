# Time-k
for RAND_SEED in 2021 2022 2023 2024 2025;
do
    for K in 100 200 300
    do
    ./imm_discrete -dataset graph_16m/ -k $K -model LT -epsilon 0.28 -epsilon1 0.22 -truncated True -RAND_SEED $RAND_SEED
    ./imm_discrete -dataset graph_16m/ -k $K -model LT -epsilon 0.28 -epsilon1 0.22 -truncated False -RAND_SEED $RAND_SEED
    done
done