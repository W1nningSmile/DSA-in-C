## Result of the performance test:

|       i       |   user time   |
|---------------|---------------|
|       10      |    0m0.000s   |
|       50      |    0m0.001s   |
|      100      |    0m0.001s   |
|      1000     |    0m0.001s   |
|     10000     |    0m0.032s   |
|     100000    |    0m3.392s   |

## What this shows us:
The runtime is too short for smaller arrays (under 1000) to be able to tell the difference. Past that, it grows quadratically since 10x the data costs about 100x the time, which is consistent with its time complexity of O(n^2).

