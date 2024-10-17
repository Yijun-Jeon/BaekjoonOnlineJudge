# [Gold Ⅰ] 그래프 트리 분할 - 22954

[문제 링크](https://www.acmicpc.net/problem/22954) 

### 성능 요약

메모리: 9424 KB, 시간: 72 ms

### 분류

* 자료 구조
* 그래프 이론
* 그래프 탐색
* 트리
* 해 구성하기
* 많은 조건 분기
* 분리 집합

### 문제 설명

정점 N개, 간선 M개의 그래프가 주어진다.

각 정점은 1부터 N까지 번호가 매겨져 있고, 간선도 입력되는 순서대로 1부터 M까지 번호가 매겨져 있다.

그래프에서 원하는 만큼 간선을 삭제해, 서로 다른 크기의 트리 2개로 분할해보자!

각각의 트리는 하나 이상의 정점을 가지고 있어야 하며, 두 트리가 동일한 정점이나 간선을 공유해서는 안 된다.

### 입력 

<p>첫 번째 줄에 정점의 개수 <math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math>, 간선의 개수 <math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math>이 주어진다. (<math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn><mo>≤</mo><mi>M</mi><mo>≤</mo><mn>200</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math>)
</p>

<p>두 번째 줄부터 <math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math>줄에 걸쳐서 간선을 나타내는 정수 <math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi></math>와&nbsp;<math xmlns="http://www.w3.org/1998/Math/MathML"><mi>v</mi></math>가 주어진다. (<math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>u</mi><mo>,</mo><mi>v</mi><mo>≤</mo><mi>N,&nbsp;</mi></math><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>u</mi><mo>≠</mo><mi>v</mi></math>)</p>

이는 u번 정점과 v번 정점을 잇는 양방향 간선이 존재함을 나타낸다. 중복 간선은 주어지지 않는다.

### 출력 


<p>그래프를 분할할 수 없다면 첫 번째 줄에 <code><span style="color:#e74c3c;">-1</span></code>을 출력하고 종료한다.</p>

<p>분할 할 수 있는 방법이 존재한다면, 아무거나 하나, 아래와 같은 형식으로 출력한다.</p>

<p>첫 번째 줄에 두 트리의 크기 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>1</mn></msub><mo>,</mo><msub><mi>N</mi><mn>2</mn></msub></math>을 출력한다. (<math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>1</mn></msub></math>과 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>2</mn></msub></math>는 서로 다른 양의 정수이고, <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>1</mn></msub><mo>+</mo><msub><mi>N</mi><mn>2</mn></msub><mo>=</mo><mi>N</mi></math>을 만족해야 한다.)</p>

<p>두 번째 줄에는 첫 번째 트리에 속한 정점 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>1</mn></msub></math>개의 번호를&nbsp;출력한다.</p>

<p>세 번째 줄에는 첫 번째 트리에 속한 간선 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>1</mn></msub><mo>−</mo><mn>1</mn></math>개의 번호를 출력한다.</p>

<p>네 번째 줄에는 두 번째 트리에 속한 정점 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>2</mn></msub></math>개의&nbsp;번호를&nbsp;출력한다.</p>

<p>다섯 번째 줄에는 두 번째 트리에 속한 간선 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>N</mi><mn>2</mn></msub><mo>−</mo><mn>1</mn></math>개의 번호를 출력한다.</p>

<p>출력한 트리 각각은 연결 그래프이고, 동일한 정점이나 간선을 공유해서는 안된다.</p>

<p>출력하는 모든 정점의 번호는 <math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math>이상 <math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math>이하를, 간선의 번호는 <math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math>이상 <math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math>이하를&nbsp;만족해야 한다.</p>
