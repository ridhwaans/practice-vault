class Frame
  attr_accessor :rolls

  def initialize
    @rolls = ""
  end

  def filled?
    return true if @rolls == "X"
    return true if @rolls.size == 2
    return false
  end

  def roll(pins)
    # validate
    raise Game::BowlingError if pins.to_i < 0
    raise Game::BowlingError if pins.to_i > 10

    raise Game::BowlingError if ["","/", "X"].include?(@rolls) && pins.to_s == "/"
    raise Game::BowlingError if ((@rolls == @rolls.to_i.to_s) && ["X", "10"].include?(pins.to_s))
    raise Game::BowlingError if ((@rolls == @rolls.to_i.to_s) && (pins.to_s == pins.to_i.to_s) && (@rolls.to_i + pins.to_i) > 10)

    # update rolls
    pins = "X" if pins == 10
    pins = "/" if @rolls.to_i + pins.to_i == 10
    @rolls << pins.to_s
  end

end


class Game
  class BowlingError < StandardError
  end

  attr_reader :frames, :total, :curr
  
  def initialize
    @frames = Array.new(12) {Frame.new} # ten frames starting at frame 0, plus two buffer frames 
    @curr, @total = 0
  end

  def roll(pins)
    raise BowlingError if @curr > 9 && ( ["/","X"].any? {|letter| @frames[9].rolls.include?(letter)} == false)
    raise BowlingError if @frames[9].rolls[1] == "/" && @frames[10].rolls.size == 1
    raise BowlingError if @frames[9].rolls == "X" && @frames[10].rolls.size == 2

    #p "current frame: #{@curr}"
    #p "pins: #{pins}"
    @frames[@curr].roll(pins)
    if @frames[@curr].filled?
      @curr += 1 
    end
  end
  
  def print_frames
    @frames.each_with_index do |frame, idx|
      p "Frame ##{idx+1}: #{frame.rolls}"
    end
  end

  def get_all_rolls_from_previous_n_frames(n=12)
    previous_rolls = ""
    (0..n-1).each_with_index do |i, idx|
      previous_rolls << @frames[i].rolls
    end
    previous_rolls.chars
  end
  
  def roll_number_of_nth_frame(n)
    previous_rolls = ""
    (0..n-1).each_with_index do |i, idx|
      previous_rolls << @frames[i].rolls
    end
    previous_rolls.length
  end

  def calculate_tenth
    score = 0
    first = @frames[9].rolls[0]
    second = @frames[9].rolls[1] if @frames[9].rolls.size == 2
    score += 10 if first == "X"
    score += (10 - first.to_i) if second == "/" 
    score += (first.to_i + second.to_i) # non integers default to 0

    fill_ball = nil
    if @frames[9].rolls == "X" || @frames[9].rolls[1] == "/" 
      fill_ball = @frames[10].rolls[0] 
      fill_ball = 10 if fill_ball == "X"
      fill_ball = fill_ball.to_i if fill_ball != "/"

      if @frames[9].rolls == "X" && fill_ball == 10
        second_bonus = @frames[11].rolls[0]
        raise BowlingError if second_bonus.nil? || second_bonus == "" || second_bonus == "/"
        second_bonus = 10 if second_bonus == "X"
        fill_ball += second_bonus.to_i
      end

      if @frames[9].rolls == "X" && fill_ball != 10
        fill_ball += (10 - @frames[10].rolls[0].to_i) if @frames[10].rolls[1] == "/" 
        fill_ball += @frames[10].rolls[1].to_i if @frames[10].rolls.size == 2
      end
    end
    score += fill_ball.to_i
    #p "10th frame score #{score}"
    score
  end

  def score
    #self.print_frames
    raise BowlingError if self.get_all_rolls_from_previous_n_frames.size == 0 || @frames[9].filled? == false
    raise BowlingError if ( ["/","X"].any? {|letter| @frames[9].rolls.include?(letter)} ) && @frames[10].rolls.size == 0

    @total = 0
    all_rolls = self.get_all_rolls_from_previous_n_frames() 
    tenth = self.roll_number_of_nth_frame(9) # calculate tenth frame separately
    #p all_rolls
    all_rolls.each_with_index do |roll, i|
      break if i == tenth
      score = 0
      bonus_rolls = 0
      bonus_rolls += 1 if roll == "/"
      bonus_rolls += 2 if roll == "X"

      score += roll.to_i if ["X", "/"].include?(roll) == false
      score += (10 - all_rolls[i-1].to_i) if roll == "/" 
      score += 10 if roll == "X"
      
      while bonus_rolls > 0
        i += 1
        score += all_rolls[i].to_i if ["X", "/"].include?(all_rolls[i]) == false
        score += (10 - all_rolls[i-1].to_i) if all_rolls[i] == "/"
        score += 10 if all_rolls[i] == "X"
        bonus_rolls -= 1
      end
      #p "score #{score}"
      @total += score
      #p "total #{@total}"
    end
    @total += self.calculate_tenth
    @total
  end

end