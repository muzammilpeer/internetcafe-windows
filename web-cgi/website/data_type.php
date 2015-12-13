<?php
error_reporting(E_ALL);
$string="hello";
$l=$string{1};
echo $l;
echo $string;
$fruits = array('strawberry' => 'red', 'banana' => 'yellow');
echo  "array is " .$fruits['banana'];
//echo "A banana is " . $fruits['banana->yellow'] . ".";



$str = <<<EOD
Example of string
spanning multiple lines
using heredoc syntax.
EOD;
class foo
{
    var $foo;
    var $bar;

    function foo()
    {
        $this->foo = 'Foo';
        $this->bar = array('Bar1', 'Bar2', 'Bar3');
    }
}

$foo = new foo();
$name = 'MyName';

echo <<<EOT
My name is "$name". I am printing some $foo->foo.
Now, I am printing some {$foo->bar[1]}.
This should print a capital 'A': \t 41

EOT;

$a=15.45;
echo " $a ";
echo gettype($a);
//settype($a,bool);
var_dump((bool)array(12));
echo '\n';
if(is_int($a))
{
echo ' "int hai" ';
}
else if(is_float($a))
{
echo ' "float hai" ';
}
if(is_bool($a))
{
echo ' "bool hai" ';
}
echo " $a ";
?>