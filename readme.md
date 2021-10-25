数値積分の練習

* trapezoidal
<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}f(x)dx\approx&space;T_{n}" />
<img src="https://latex.codecogs.com/gif.latex?T_n=h\left(\frac{1}{2}f(a)&plus;\sum_{i=1}^{n-1}f(a&plus;hi)&plus;\frac{1}{2}f(b)\right)" />
<img src="https://latex.codecogs.com/gif.latex?h=\frac{b-a}{n}" />

* midpoint
<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}f(x)dx\approx&space;M_{n}" />
<img src="https://latex.codecogs.com/gif.latex?M_n=h\left(\sum_{i=1}^{n-1}f(a&plus;h(i-1/2))\right)" />
<img src="https://latex.codecogs.com/gif.latex?h=\frac{b-a}{n}" />

* simpson
<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}f(x)dx\approx&space;S_{n}" />
<img src="https://latex.codecogs.com/gif.latex?S_n=\frac{h}{3}\left(\frac{1}{2}f(a)&plus;\sum_{i=1}^{n-1}f(a&plus;hi)&plus;\frac{1}{2}f(b)&plus;2\sum_{i=1}^{n-1}f(a&plus;h(i-1/2))\right)" />
<img src="https://latex.codecogs.com/gif.latex?h=\frac{b-a}{n}" />

* tanh
<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}f(x)dx=\int_{-\infty}^{\infty}\varphi(t)\varphi'(t)dt\approx&space;E_n" />
<img src="https://latex.codecogs.com/gif.latex?E_{n}=h\sum_{i=-n}^{n}f(\tanh&space;ih)\frac{1}{\cosh^{2}ih}" />
<img src="https://latex.codecogs.com/gif.latex?h=\sqrt{\frac{6n\pi}{n}}" />

* dexp-finite
<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{b}f(x)dx=\int_{-\infty}^{\infty}\varphi(t)\varphi'(t)dt\approx&space;DE_n" />
<img src="https://latex.codecogs.com/gif.latex?DE_{n}=h\sum_{i=-n}^{n}f(\varphi(ih))\varphi'(ih)" />
<img src="https://latex.codecogs.com/gif.latex?\varphi(t)&space;=&space;\frac{b-a}{2}\tanh\left(\frac{\pi}{2}\sinh&space;t&space;\right&space;)&space;&plus;&space;\frac{a&plus;b}{2}" />
<img src="https://latex.codecogs.com/gif.latex?\varphi'(t)&space;=&space;\frac{b-a}{4}\frac{\pi&space;\cosh&space;t}{\cosh^{2}(\frac{\pi}{2}\sinh&space;t)}" />
<img src="https://latex.codecogs.com/gif.latex?h=\frac{\log(3n)}{n}" />

* dexp-semi_infinite
<img src="https://latex.codecogs.com/gif.latex?\int_{a}^{\infty}f(x)dx=\int_{-\infty}^{\infty}\varphi(t)\varphi'(t)dt\approx&space;DE_n" />
<img src="https://latex.codecogs.com/gif.latex?DE_{n}=h\sum_{i=-n}^{n}f(\varphi(ih))\varphi'(ih)" />
<img src="https://latex.codecogs.com/gif.latex?\varphi(t)&space;=&space;a&space;&plus;&space;\exp(\frac{\pi}{2}\sinh&space;t)" />
<img src="https://latex.codecogs.com/gif.latex?\varphi'(t)&space;=&space;\frac{\pi}{2}\cosh(t)\exp(\frac{\pi}{2}\sinh&space;t)" />
<img src="https://latex.codecogs.com/gif.latex?h=\frac{\log(3n)}{n}" />

* dexp-infinite
<img src="https://latex.codecogs.com/gif.latex?\int_{-\infty}^{\infty}f(x)dx=\int_{-\infty}^{\infty}\varphi(t)\varphi'(t)dt\approx&space;DE_n" />
<img src="https://latex.codecogs.com/gif.latex?DE_{n}=h\sum_{i=-n}^{n}f(\varphi(ih))\varphi'(ih)" />
<img src="https://latex.codecogs.com/gif.latex?\varphi(t)&space;=&space;\sinh(\frac{\pi}{2}\sinh&space;t)" />
<img src="https://latex.codecogs.com/gif.latex?\varphi'(t)&space;=&space;\frac{\pi}{2}\cosh(t)\cosh(\frac{\pi}{2}\sinh(t))" />
<img src="https://latex.codecogs.com/gif.latex?h=\frac{\log(3n)}{n}" />
