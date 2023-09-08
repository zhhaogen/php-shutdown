--TEST--
Check if shutdown is loaded
--EXTENSIONS--
shutdown
--FILE--
<?php
echo 'The extension "shutdown" is available';
?>
--EXPECT--
The extension "shutdown" is available
