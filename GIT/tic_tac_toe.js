v=1;
c=5;
current=0;
var myarray=[[0,0,0],[0,0,0],[0,0,0]];
function restart()
{
	
		document.location.reload();
	
}
function Func(x)
{
	

		var val=document.getElementById(x).value;
	if(v%2!=0&&val=="-1")
	{
	document.getElementById(x).value="X";
	document.getElementById(x).style.backgroundColor="red";
	myarray[current]=x;
	curren=current+1;
	v=v+1;
	}
	else if(v%2==0&&val=="-1")
	{
		document.getElementById(x).value="O";
		document.getElementById(x).style.backgroundColor="yellow";
		myarray[current]=x;
		curren=current+1;
		v=v+1;
	}
	else{
		alert("invalid move");
		return ;
		
	}
	
	/*var myarray[0][0]=document.getElementById("1").value;
	var myarray[0][1]=document.getElementById("2").value;
	var myarray[0][2]=document.getElementById("3").value;
			
	var myarray[1][0]=document.getElementById("4").value;
	var myarray[1][1]=document.getElementById("5").value;
	var myarray[1][2]=document.getElementById("6").value;
	var myarray[2][0]=document.getElementById("7").value;
	var myarray[2][1]=document.getElementById("8").value;
	var myarray[2][2]=document.getElementById("9").value;
	*/
	
	
	
	
	var a=document.getElementById("1").value;
	var b=document.getElementById("2").value;
	var c=document.getElementById("3").value;
			
	var d=document.getElementById("4").value;
	var e=document.getElementById("5").value;
	var f=document.getElementById("6").value;
	var g=document.getElementById("7").value;
	var h=document.getElementById("8").value;
	var i=document.getElementById("9").value;
	
	if(a==b &&b==c &&a!="-1" &&b!="-1")
	{
		alert(a+" won");
		setTimeout(restart,5000);
		
		
	}
	else if(a==d &&d==g&&a!="-1" &&d!="-1")
	{
		alert(a+" won");
	setTimeout(restart,5000);
		
	}
	else if(a==e &&e==i&&a!="-1" &&e!="-1")
	{
		alert(a+" won");
		setTimeout(restart,5000);
	}
	else if(b==e &&e==h&&e!="-1" &&b!="-1")
	{
		alert(b+" won");
		setTimeout(restart,5000);
	}
	else if(c==f &&f==i&&c!="-1" &&f!="-1")
	{
		alert(c+" won");
		setTimeout(restart,5000);
	}
	else if(c==e &&c==g&&c!="-1" &&e!="-1")
	{
		alert(c+" won");
		setTimeout(restart,5000);
	}
	else if(e==d &&d==f&&e!="-1" &&d!="-1")
	{
		alert(d+" won");
		setTimeout(restart,5000);
	}
	else if(g==h &&i==g&&g!="-1" &&h!="-1")
	{
		alert(g+" won");
		setTimeout(restart,5000);
	}
	if(v==11)
	{
		alert("tie");			
	setTimeout(restart,5000);
	}
	
	

	
}


function pre()
{
	if(current-1>=0)
	{
		var loc=parseInt(myarray[current-1],10);
	document.getElementById(loc)="-1";
	document.getElementById(loc).style.backgroundColor="white";
	current=current-1;
	}
	
}
function next()
{
	if(current<=8)
	{
		var loc=parseInt(myarray[current+1],10);
	document.getElementById(loc)="-1";
	document.getElementById(loc).style.backgroundColor="white";
	current=current+1;
	}
	
}
