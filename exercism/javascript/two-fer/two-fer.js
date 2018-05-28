var TwoFer = function () {};

TwoFer.prototype.twoFer = function (who) {
	return "One for {0}, one for me.".format((who == null || who.trim() == "") ? "you" : who);
};

String.prototype.format = function() {
  a = this;
  for (k in arguments) {
    a = a.replace("{" + k + "}", arguments[k])
  }
  return a
}

module.exports = TwoFer;
