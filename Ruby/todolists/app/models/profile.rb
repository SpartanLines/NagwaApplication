class Profile < ActiveRecord::Base
    belongs_to :user

    validates :gender ,  inclusion: { in: %w(male female)}
    validate :is_man_named
    validate :has_name
   scope  :order_year, -> {order birth_year: :asc}
    def is_man_named
        if gender=="male" and first_name=="Sue"
            errors.add(:first_name,"Your first name can not be sue buddy!")
        end
    end
    def has_name
        if first_name.nil? and last_name.nil?
        errors.add(:first_name,"You must have a name")
        end
    end
    def self.get_all_profiles(min,max)
        Profile.where("birth_year BETWEEN ? AND ?",min,max).order_year
    end
end
