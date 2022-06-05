export const twoFer = (who) => {
  if (who == null || who.trim() == "") {
    who = 'you';
  }
  return `One for ${who}, one for me.`;
}