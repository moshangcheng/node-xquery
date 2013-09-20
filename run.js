var zorba = require('./build/Debug/zorba');
try {
  var r = zorba.execute("<a />");
  console.log(r);
} catch (e) {
  console.log("error");
}
