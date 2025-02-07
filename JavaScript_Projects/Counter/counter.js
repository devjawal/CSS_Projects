const count=document.querySelector('#count');
let i=document.querySelector('#i');
let d=document.querySelector('#d');
function dec(){
    let value=parseInt(count.innerHTML);
    value-=1;
    count.innerHTML = value;

};
function inc(){
    let value=parseInt(count.innerHTML);
    value+=1;
    count.innerHTML = value;

};
i.addEventListener('click',inc);
d.addEventListener('click',dec);