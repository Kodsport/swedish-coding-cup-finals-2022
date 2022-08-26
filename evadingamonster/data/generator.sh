#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution sl_mlogn.cpp opt

compile gen_random.py
compile gen_bigans.py
compile gen_alt.py

samplegroup
limits n=100 m=500
sample 1
sample 2

group group1 23
limits n=100 m=500

tc 1
tc 2
tc small-smalldeg-rand-drunk gen_random n=100 m=500 deg=3 mode=random walk=drunk
tc small-line-drunk gen_random n=100 m=500 deg=3 mode=line walk=drunk
tc small-tinystar gen_random n=4 m=500 mode=star walk=drunk
tc small-small1-drunk gen_random n=7 m=500 deg=3 mode=random walk=drunk
tc small-small2-drunk gen_random n=8 m=500 mode=random walk=drunk

group group2 27
limits n=100000 m=500000 deg=3

tc 1
tc 2
tc small-smalldeg-rand-drunk
tc small-line-drunk
tc small-small1-drunk
tc smalldeg-rand-drunk gen_random n=100000 m=500000 deg=3 mode=random walk=drunk
tc smalldeg-deep-drunk gen_random n=100000 m=500000 deg=3 mode=deep walk=drunk
tc smalldeg-line-drunk gen_random n=100000 m=500000 deg=3 mode=line walk=drunk
tc smalldeg-tinystar gen_bigans n=4 m=500000
tc smalldeg-bigans gen_bigans n=100000 m=500000
tc smalldeg-small-drunk gen_random n=10 m=500000 deg=3 mode=random walk=drunk

group group3 50
limits n=100000 m=500000
include_group group1
include_group group2

tc large-rand-drunk gen_random n=100000 m=500000 mode=random walk=drunk
tc large-star-drunk gen_random n=100000 m=500000 mode=star walk=drunk
tc large-deep-drunk gen_random n=100000 m=500000 mode=deep walk=drunk
tc large-small-drunk gen_random n=10 m=500000 mode=random walk=drunk
tc large-alt gen_alt n=100000 m=500000
