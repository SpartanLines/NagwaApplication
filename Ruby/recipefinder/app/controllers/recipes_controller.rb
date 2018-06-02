class RecipesController < ApplicationController
  def index
    @searchterm=params[:search] || "chocolate"
    @recipes=Recipe.for(@searchterm)
  end
end
