var zorba = require('./build/Debug/zorba');
try {
  var r = zorba.execute("for $x in 1 to 3 return <v>{$x}</v>" );
  console.log(r);
} catch (e) {
  console.log("error");
}
