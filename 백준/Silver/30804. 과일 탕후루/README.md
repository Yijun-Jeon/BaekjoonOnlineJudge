# [Silver Ⅱ] 과일 탕후루 - 30804

[문제 링크](https://www.acmicpc.net/problem/30804) 

### 성능 요약

메모리: 1892 KB, 시간: 24 ms

### 분류

* 구현
* 브루트포스 알고리즘
* 두 포인터

### 문제 설명

<p>은하는 긴 막대에 N개의 과일이 꽂혀있는 과일 탕후루를 만들었습니다. 과일의 각 종류에는 1부터 9까지의 번호가 붙어있고, 앞쪽부터 차례로 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>S</mi><mn>1</mn></msub><mo>,</mo><msub><mi>S</mi><mn>2</mn></msub><mo>,</mo><mo>⋯</mo><mo>,</mo><msub><mi>S</mi><mi>N</mi></msub></math>번 과일이 꽂혀있습니다. 과일 탕후루를 다 만든 은하가 주문을 다시 확인해보니 과일을 두 종류 이하로 사용해달라는 요청이 있었습니다.</p>

<p>탕후루를 다시 만들 시간이 없었던 은하는, 막대의 앞쪽과 뒤쪽에서 몇 개의 과일을 빼서 두 종류 이하의 과일만 남기기로 했습니다. 앞에서 a개, 뒤에서 b개의 과일을 빼면 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>S</mi><mrow data-mjx-texclass="ORD"><mi>a</mi><mo>+</mo><mn>1</mn></mrow></msub><mo>,</mo><msub><mi>S</mi><mrow data-mjx-texclass="ORD"><mi>a</mi><mo>+</mo><mn>2</mn></mrow></msub><mo>,</mo><mo>⋯</mo><mo>,</mo><msub><mi>S</mi><mrow data-mjx-texclass="ORD"><mi>N</mi><mo>−</mo><mi>b</mi><mo>−</mo><mn>1</mn></mrow></msub><mo>,</mo><msub><mi>S</mi><mrow data-mjx-texclass="ORD"><mi>N</mi><mo>−</mo><mi>b</mi></mrow></msub></math>번 과일, 총 N−(a+b)개가 꽂혀있는 탕후루가 됩니다. <math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn><mo>≤</mo><mi>a</mi><mo>,</mo><mi>b</mi><mo>;</mo></math><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi><mo>+</mo><mi>b</mi><mo>&lt;</mo><mi>N</mi><mo stretchy="false">)</mo></math>
<p>이렇게 만들 수 있는 과일을 두 종류 이하로 사용한 탕후루 중에서, 과일의 개수가 가장 많은 탕후루의 과일 개수를 구하세요.</p>

### 입력 

<p>첫 줄에 과일의 개수 N이 주어집니다. <math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>200</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math>

<p>둘째 줄에 탕후루에 꽂힌 과일을 의미하는 N개의 정수 <math xmlns="http://www.w3.org/1998/Math/MathML"><msub><mi>S</mi><mn>1</mn></msub><mo>,</mo><mo>⋯</mo><mo>,</mo><msub><mi>S</mi><mi>N</mi></msub></math>이 공백으로 구분되어 주어집니다.<math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>1</mn><mo>≤</mo><msub><mi>S</mi><mi>i</mi></msub><mo>≤</mo><mn>9</mn><mo stretchy="false">)</mo></math>

### 출력 

문제의 방법대로 만들 수 있는 과일을 두 종류 이하로 사용한 탕후루 중에서, 과일의 개수가 가장 많은 탕후루의 과일 개수를 첫째 줄에 출력하세요.
